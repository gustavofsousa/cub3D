#include "../../include/cub3d.h"

void	load_textures(t_data *data)
{
	data->texture_height = 64;
	data->texture_width = 64;
	for (int x = 0; x < data->texture_width; x++)
	{
		for (int y = 0 ; y < data->texture_height; y ++)
		{
			int xorcolor = (x * 256 / data->texture_width) ^ (y * 256 / data->texture_height);
			//int xcolor = x * 256 / data->texture_width;
			int ycolor = y * 256 / data->texture_height;
			int xycolor = y * 128 / data->texture_height + x * 128 / data->texture_width;
			data->texture[0][data->texture_width * y + x] = 65536 * 254 * (x != y && x != data->texture_width - y); //flat red texture with black cross
			data->texture[1][data->texture_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			data->texture[2][data->texture_width * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			data->texture[3][data->texture_width * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			data->texture[4][data->texture_width * y + x] = 256 * xorcolor; //xor green
			data->texture[5][data->texture_width * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			data->texture[6][data->texture_width * y + x] = 65536 * ycolor; //red gradient
			data->texture[7][data->texture_width * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}
}

t_double_vector	calc_ray_dir(int x, t_data *data)
{
	double	w;
	t_double_vector ray_dir;

	double cameraX;
	w = LENGHT;
	cameraX = 2.0 * x / (double)w - 1.0;

	ray_dir.x = data->player.dirX + data->player.cam_plane_dirX * cameraX;
	ray_dir.y = data->player.dirY + data->player.cam_plane_dirY * cameraX;
	return (ray_dir);
}

void	calc_wall_hit(t_data *data, t_ray_info *ray)
{
		t_double_vector	sideDist;
		t_double_vector	deltaDist; //C has infinity, so theres is no need to check ray->dir and assign 1e30
		t_int_vector	step;

		ray->map_hit_coord.x = trunc(data->player.play_x); //current square of the ray->map_hit_coord, the ray is in
		ray->map_hit_coord.y = trunc(data->player.play_y); //current square of the ray->map_hit_coord, the ray is in
		deltaDist.x = fabs(1.0 / ray->dir.x);
		deltaDist.y = fabs(1.0 / ray->dir.y);

		int hit; //was there a wall hit?
		hit = 0; //was there a wall hit?

		if (ray->dir.x < 0)
		{
			step.x = -1;
			sideDist.x = (data->player.play_x - ray->map_hit_coord.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (ray->map_hit_coord.x + 1.0 - data->player.play_x) * deltaDist.x;
		}
		if (ray->dir.y < 0)
		{
			step.y = -1;
			sideDist.y = (data->player.play_y - ray->map_hit_coord.y) * deltaDist.y;
		}
		else
		{
			step.y = 1;
			sideDist.y = (ray->map_hit_coord.y + 1.0 - data->player.play_y) * deltaDist.y;
		}

		while (hit == 0)
		{
		//jump to next data->map square, either in x-direction, or in y-direction
		// printf("sideDist.x:%f sideDist.y:%f , deltaDist.x:%f destaDistY:%f\n", sideDist.x, sideDist.y, deltaDist.x, deltaDist.y); 
			if (sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				ray->map_hit_coord.x += step.x;
				ray->side_hit = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				ray->map_hit_coord.y += step.y;
				ray->side_hit = 1;
			}
			//Check if ray has hit a wall
			if (data->map[ray->map_hit_coord.x][ray->map_hit_coord.y] > 0)
				hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (ray->side_hit == 0)
			ray->perp_wall_dist = (sideDist.x - deltaDist.x);
		else
			ray->perp_wall_dist = (sideDist.y - deltaDist.y);
}

void	render_walls(t_data* data, int color_A, int color_B) // create ray structure
{
	double	w;
	int		x;
	t_ray_info ray;

	w = LENGHT;
	x = 0;
	while (x < w)
	{
		ray.dir = calc_ray_dir(x, data);
		calc_wall_hit(data, &ray);
	
		int h; //h is the height in pixels of the screen, that way we transform from data->map to pixel coordinates
		h = HEIGHT; //h is the height in pixels of the screen, that way we transform from data->map to pixel coordinates

		int lineHeight;
		lineHeight = (int)(h / ray.perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart;
		drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) //guarantee not to draw outside the screen/image
			drawStart = 0;
		
		int drawEnd;
		drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) //guarantee not to draw outside the screen/image
			drawEnd = h - 1;

		int texture_i = data->map[ray.map_hit_coord.x][ray.map_hit_coord.y] - 1;

		// load_textures(data); -> already beeing called at render_ray.map_hit_coord3D;
		// uint32_t buffer[HEIGHT][LENGHT];
		//calculate value of tile_hit_coord -> position the ray hit the tile
		double tile_hit_X; //where exactly the wall was hit
		if (ray.side_hit == 0)
			tile_hit_X = data->player.play_y + ray.perp_wall_dist * ray.dir.y;
		else
			tile_hit_X = data->player.play_x + ray.perp_wall_dist * ray.dir.x;
		
		tile_hit_X -= floor((tile_hit_X)); //just the decimal portion

		//x coordinate on the texture
		int texture_hit_X;
		texture_hit_X = tile_hit_X * (double)data->texture_width;
		if(ray.side_hit == 0 && ray.dir.x > 0)
			texture_hit_X = data->texture_width - texture_hit_X - 1;
		if(ray.side_hit == 1 && ray.dir.y < 0)
			texture_hit_X = data->texture_width - texture_hit_X - 1;

		 double stepTex;
		 stepTex = 1.0 * data->texture_height / lineHeight;
		// Starting texture coordinate
		double texPos;
		texPos = (drawStart - h / 2 + lineHeight / 2) * stepTex;
		for(int y = drawStart; y<drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY;
			texY = (int)texPos & (data->texture_height - 1);
			texPos += stepTex;
			unsigned long color = data->texture[texture_i][data->texture_height * texY + texture_hit_X];
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (ray.side_hit == 1)
				color = (color >> 1) & 8355711;
			pixel_put(&data->img, x, y, color);
		}
		x++;
	}
}


void	draw_player_square(t_img *img, t_player player, int l)
{
	int	x;
	int	y;
	int	y_pxl;
	int	x_pxl;

	x_pxl = 22 * player.play_x;
	y_pxl = 22 * player.play_y;
	x = x_pxl - l / 2;
	while (x < x_pxl + l / 2) //draw player square
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

	plan_xn = (player.play_x + player.dirX - player.cam_plane_dirX) * 22;
	plan_yn = (player.play_y + player.dirY - player.cam_plane_dirY) * 22;
	plan_xp = (player.play_x + player.dirX + player.cam_plane_dirX) * 22;
	plan_yp = (player.play_y + player.dirY + player.cam_plane_dirY) * 22;
	draw_player_square(img, player, l);
	player.dirx_pxl = (player.play_x + player.dirX) * 22;
	player.diry_pxl = (player.play_y + player.dirY) * 22;
	draw_line (img, (int [2]){player.play_x * 22, player.play_y * 22},
		(int [2]){player.dirx_pxl, player.diry_pxl}, 0x0000FF);
	pixel_put(img, plan_xn, plan_yn, 0x0000FF);
	pixel_put(img, plan_xp, plan_yp, 0x0000FF);
}
