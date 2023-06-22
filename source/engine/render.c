#include "../../include/cub3d.h"

void	load_textures(t_data *data)
{
	data->tex_height = 64;
	data->tex_width = 64;
	for (int x = 0; x < data->tex_width; x++)
	{
		for (int y = 0 ; y < data->tex_height; y ++)
		{
			int xorcolor = (x * 256 / data->tex_width) ^ (y * 256 / data->tex_height);
			//int xcolor = x * 256 / data->tex_width;
			int ycolor = y * 256 / data->tex_height;
			int xycolor = y * 128 / data->tex_height + x * 128 / data->tex_width;
			data->tex[0][data->tex_width * y + x] = 65536 * 254 * (x != y && x != data->tex_width - y); //flat red tex with black cross
			data->tex[1][data->tex_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			data->tex[2][data->tex_width * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			data->tex[3][data->tex_width * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			data->tex[4][data->tex_width * y + x] = 256 * xorcolor; //xor green
			data->tex[5][data->tex_width * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			data->tex[6][data->tex_width * y + x] = 65536 * ycolor; //red gradient
			data->tex[7][data->tex_width * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey tex
		}
	}
}

t_double_vector	calc_ray_dir(int x, t_data *data)
{
	t_double_vector ray_dir;

	double cameraX;
	cameraX = 2.0 * x / (double)LENGHT - 1.0;

	ray_dir.x = data->player.dirX + data->player.cam_plane_dirX * cameraX;
	ray_dir.y = data->player.dirY + data->player.cam_plane_dirY * cameraX;
	return (ray_dir);
}

void	calc_ray_info(t_data *data, t_ray_info *ray)
{
	ray->map_hit.x = trunc(data->player.x); //current square of the ray->map_hit, the ray is in
	ray->map_hit.y = trunc(data->player.y); //current square of the ray->map_hit, the ray is in
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (data->player.x - ray->map_hit.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_hit.x + 1.0 - data->player.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (data->player.y - ray->map_hit.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_hit.y + 1.0 - data->player.y) * ray->delta.y;
	}
}

void	calc_wall_hit(t_data *data, t_ray_info *ray)
{
	int hit;
	hit = 0;
	while (hit == 0)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map_hit.x += ray->step.x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map_hit.y += ray->step.y;
			ray->side_hit = 1;
		}
		if (data->map[ray->map_hit.x][ray->map_hit.y] > 0)
			hit = 1;
	}
}

void	calc_perp_wall_dist(t_data *data, t_ray_info *ray)
{
		calc_ray_info(data, ray);
		calc_wall_hit(data, ray);
		if (ray->side_hit == 0)
			ray->perp_wall_dist = (ray->side.x - ray->delta.x);
		else
			ray->perp_wall_dist = (ray->side.y - ray->delta.y);
}

int	calc_lowest_pixel (int line_height)
{
	int drawStart;
	drawStart = -line_height / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	return (drawStart);
}

int	calc_highest_pixel (int line_height)
{
	int drawEnd;
	drawEnd = line_height / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	return (drawEnd);
}

double	calc_tile_hit_x (t_data *data, t_ray_info *ray)
{
		double tile_hit_X;

		if (ray->side_hit == 0)
			tile_hit_X = data->player.y + ray->perp_wall_dist * ray->dir.y;
		else
			tile_hit_X = data->player.x + ray->perp_wall_dist * ray->dir.x;
		
		tile_hit_X -= floor((tile_hit_X));
		return (tile_hit_X);
}

int	calc_tex_hit_x(t_data *data, t_ray_info *ray)
{
	int tex_hit_X;
	double tile_hit_X;

	tile_hit_X = calc_tile_hit_x(data, ray);
	tex_hit_X = tile_hit_X * (double)data->tex_width;
	if((ray->side_hit == 0 && ray->dir.x > 0) ||
		(ray->side_hit == 1 && ray->dir.y < 0))
		tex_hit_X = data->tex_width - tex_hit_X - 1;
	return (tex_hit_X);
}

unsigned long	tex_color(t_data *data, int tex_pos, int tex_i, int tex_hit_x)
{
	int texY;

	texY = (int)tex_pos & (data->tex_height - 1);
	return (data->tex[tex_i][data->tex_height * texY + tex_hit_x]);
}

void	draw_x_line(t_data *data, t_ray_info *ray, int line_height, int x)
{
	int draw_limits[2];
	double stepTex;
	double tex_pos;
	int tex_i;
	int	tex_hit_x;

	tex_i = data->map[ray->map_hit.x][ray->map_hit.y] - 1;
	tex_hit_x = calc_tex_hit_x(data, ray);
	draw_limits[0] = calc_lowest_pixel(line_height);
	draw_limits[1] = calc_highest_pixel(line_height);
	stepTex = 1.0 * data->tex_height / line_height;
	tex_pos = (draw_limits[0] - HEIGHT / 2 + line_height / 2) * stepTex;
	for(int y = draw_limits[0]; y<draw_limits[1]; y++)
	{
		tex_pos += stepTex;
		if (ray->side_hit == 1)
			pixel_put(&data->img, x, y,
			(tex_color(data, tex_pos, tex_i, tex_hit_x) >> 1) & 8355711);
		else
			pixel_put(&data->img, x, y,
			tex_color(data, tex_pos, tex_i, tex_hit_x));
	}
}

void	raycast(t_data* data, int color_A, int color_B)
{
	int			x;
	int			line_height;
	t_ray_info	ray;

	x = 0;
	while (x < LENGHT)
	{
		ray.dir = calc_ray_dir(x, data);
		calc_perp_wall_dist(data, &ray);
		line_height = (int)(HEIGHT / ray.perp_wall_dist);
		draw_x_line(data, &ray, line_height, x);
		x++;
	}
}


void	draw_player_square(t_img *img, t_player player, int l)
{
	int	x;
	int	y;
	int	y_pxl;
	int	x_pxl;

	x_pxl = 22 * player.x;
	y_pxl = 22 * player.y;
	x = x_pxl - l / 2;
	while (x < x_pxl + l / 2)
	{
		y = y_pxl - l / 2;
		while (y < y_pxl + l / 2)
		{
			pixel_put(img, x, y, 0x0FF000);
			y++;
		}
		x++;
	}
}

void	render_player(t_img *img, t_player player, int l)
{
	int	plan_xn;
	int	plan_yn;
	int	plan_xp;
	int	plan_yp;

	plan_xn = (player.x + player.dirX - player.cam_plane_dirX) * 22;
	plan_yn = (player.y + player.dirY - player.cam_plane_dirY) * 22;
	plan_xp = (player.x + player.dirX + player.cam_plane_dirX) * 22;
	plan_yp = (player.y + player.dirY + player.cam_plane_dirY) * 22;
	draw_player_square(img, player, l);
	player.dirx_pxl = (player.x + player.dirX) * 22;
	player.diry_pxl = (player.y + player.dirY) * 22;
	draw_line (img, (int [2]){player.x * 22, player.y * 22},
		(int [2]){player.dirx_pxl, player.diry_pxl}, 0x0000FF);
	pixel_put(img, plan_xn, plan_yn, 0x0000FF);
	pixel_put(img, plan_xp, plan_yp, 0x0000FF);
}
