#include "../../include/cub3d.h"

void	load_textures(t_game *game)
{
	game->tex_height = 64;
	game->tex_width = 64;
	for (int x = 0; x < (int) game->tex_width; x++)
	{
		for (int y = 0 ; y < (int) game->tex_height; y ++)
		{
			int xorcolor = (x * 256 / game->tex_width) ^ (y * 256 / game->tex_height);
			//int xcolor = x * 256 / game->tex_width;
			int ycolor = y * 256 / game->tex_height;
			int xycolor = y * 128 / game->tex_height + x * 128 / game->tex_width;
			game->tex[0][game->tex_width * y + x] = 65536 * 254 * (x != y && x != game->tex_width - y); //flat red tex with black cross
			game->tex[1][game->tex_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			game->tex[2][game->tex_width * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			game->tex[3][game->tex_width * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			game->tex[4][game->tex_width * y + x] = 256 * xorcolor; //xor green
			game->tex[5][game->tex_width * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			game->tex[6][game->tex_width * y + x] = 65536 * ycolor; //red gradient
			game->tex[7][game->tex_width * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey tex
		}
	}
}

t_double_vector	calc_ray_dir(int x, t_game *game)
{
	t_double_vector ray_dir;

	double cameraX;
	cameraX = 2.0 * x / (double)LENGHT - 1.0;

	ray_dir.x = game->player.dirX + game->player.cam_plane_dirX * cameraX;
	ray_dir.y = game->player.dirY + game->player.cam_plane_dirY * cameraX;
	return (ray_dir);
}

void	calc_ray_info(t_game *game, t_ray_info *ray)
{
	ray->map_hit.x = trunc(game->player.x); //current square of the ray->map_hit, the ray is in
	ray->map_hit.y = trunc(game->player.y); //current square of the ray->map_hit, the ray is in
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (game->player.x - ray->map_hit.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_hit.x + 1.0 - game->player.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (game->player.y - ray->map_hit.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_hit.y + 1.0 - game->player.y) * ray->delta.y;
	}
}

void	calc_wall_hit(t_game *game, t_ray_info *ray)
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
		if (game->map.mtx_int[ray->map_hit.x][ray->map_hit.y] > 0)
			hit = 1;
	}
}

void	calc_perp_wall_dist(t_game *game, t_ray_info *ray)
{
		calc_ray_info(game, ray);
		calc_wall_hit(game, ray);
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

double	calc_tile_hit_x (t_game *game, t_ray_info *ray)
{
		double tile_hit_X;

		if (ray->side_hit == 0)
			tile_hit_X = game->player.y + ray->perp_wall_dist * ray->dir.y;
		else
			tile_hit_X = game->player.x + ray->perp_wall_dist * ray->dir.x;
		
		tile_hit_X -= floor((tile_hit_X));
		return (tile_hit_X);
}

int	calc_tex_hit_x(t_game *game, t_ray_info *ray)
{
	int tex_hit_X;
	double tile_hit_X;

	tile_hit_X = calc_tile_hit_x(game, ray);
	tex_hit_X = tile_hit_X * (double)game->tex_width;
	if((ray->side_hit == 0 && ray->dir.x > 0) ||
		(ray->side_hit == 1 && ray->dir.y < 0))
		tex_hit_X = game->tex_width - tex_hit_X - 1;
	return (tex_hit_X);
}

unsigned long	tex_color(t_game *game, int tex_pos, int tex_i, int tex_hit_x)
{
	int texY;

	texY = (int)tex_pos & (game->tex_height - 1);
	return (game->tex[tex_i][game->tex_height * texY + tex_hit_x]);
}

void	draw_x_line(t_game *game, t_ray_info *ray, int line_height, int x)
{
	int draw_limits[2];
	double stepTex;
	double tex_pos;
	int tex_i;
	int	tex_hit_x;

	tex_i = game->map.mtx_int[ray->map_hit.x][ray->map_hit.y] - 1;
	tex_hit_x = calc_tex_hit_x(game, ray);
	draw_limits[0] = calc_lowest_pixel(line_height);
	draw_limits[1] = calc_highest_pixel(line_height);
	stepTex = 1.0 * game->tex_height / line_height;
	tex_pos = (draw_limits[0] - HEIGHT / 2 + line_height / 2) * stepTex;
	while (draw_limits[0] < draw_limits[1])
	{
		tex_pos += stepTex;
		if (ray->side_hit == 1)
			pixel_put(&game->img, x, draw_limits[0],
			(tex_color(game, tex_pos, tex_i, tex_hit_x) >> 1) & 8355711);
		else
			pixel_put(&game->img, x, draw_limits[0],
			tex_color(game, tex_pos, tex_i, tex_hit_x));
		draw_limits[0]++;
	}
}

void	raycast(t_game* game)
{
	int			x;
	int			line_height;
	t_ray_info	ray;

	x = 0;
	while (x < LENGHT)
	{
		ray.dir = calc_ray_dir(x, game);
		calc_perp_wall_dist(game, &ray);
		line_height = (int)(HEIGHT / ray.perp_wall_dist);
		draw_x_line(game, &ray, line_height, x);
		x++;
	}
}

void	draw_background(t_game game, int ceiling_color, int floor_color)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < LENGHT)
	{
		y = 0;
		color = ceiling_color;
		while (y < HEIGHT)
		{
			if (y == HEIGHT / 2)
				color = floor_color;
			pixel_put(&game.img, x, y, color);
			y++;
		}
		x++;
	}
}
