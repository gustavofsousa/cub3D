#include "../../include/cub3d.h"

#include <stdint.h> // REMOVE AND TEST UNSIGNED LONG

void	render_map2d(t_data *data, int square_sz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COLUMN)
		{
			if (data->map[i][j] == 1)
				draw_square(&data->img, i * square_sz, j * square_sz,
					0xFF0000, 22);
			else
 				draw_square(&data->img, i * square_sz, j * square_sz,
					0xFFF000, 22);
			j++;
		}
		i++;
	}
}

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

void	render_walls(t_data* data, int color_A, int color_B) // create ray structure
{
	double w;
	w = LENGHT;
	
	for(int x = 0; x < w; x++) // USE WHILE INSTEAD
	{
		// printf("\n%i\n", x);
		//calculate ray position and direction
		double cameraX; //x-coordinate in camera space
		cameraX = 2.0 * x / (double)w - 1.0; //x-coordinate in camera space
		// printf("camerax:%f\n", cameraX);
		double rayDirX;
		double rayDirY;

		rayDirX = data->player.dirX + data->player.cam_plane_dirX * cameraX;
		rayDirY = data->player.dirY + data->player.cam_plane_dirY * cameraX;

		int mapX; //current square of the map, the ray is in
		int mapY; //current square of the map, the ray is in
		mapX = trunc(data->player.play_x); //current square of the map, the ray is in
		mapY = trunc(data->player.play_y); //current square of the map, the ray is in

		double sideDistX;
		double sideDistY;

		double deltaDistX; //C has infinity, so theres is no need to check rayDir and assign 1e30
		double deltaDistY; //C has infinity, so theres is no need to check rayDir and assign 1e30
		deltaDistX = fabs(1.0 / rayDirX); //C has infinity, so theres is no need to check rayDir and assign 1e30
		deltaDistY = fabs(1.0 / rayDirY); //C has infinity, so theres is no need to check rayDir and assign 1e30
		
		double perpWallDist;

		int stepX;
		int stepY;

		int hit; //was there a wall hit?
		hit = 0; //was there a wall hit?
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->player.play_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->player.play_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->player.play_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->player.play_y) * deltaDistY;
		}

// SPLIT FT

		while (hit == 0)
		{
		//jump to next data->map square, either in x-direction, or in y-direction
		// printf("sideDistX:%f sideDistY:%f , deltaDistX:%f destaDistY:%f\n", sideDistX, sideDistY, deltaDistX, deltaDistY); 
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map[mapX][mapY] > 0)
				hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
    	else
			perpWallDist = (sideDistY - deltaDistY);
		
		
		// printf("wall hit:%i,%i perpWallDist:%f", mapX, mapY, perpWallDist);
		//Calculate height of line to draw on screen
		int h; //h is the height in pixels of the screen, that way we transform from data->map to pixel coordinates
		h = HEIGHT; //h is the height in pixels of the screen, that way we transform from data->map to pixel coordinates
		int lineHeight;
		lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart;
		drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) //guarantee not to draw outside the screen/image
			drawStart = 0;
		
		int drawEnd;
		drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) //guarantee not to draw outside the screen/image
			drawEnd = h - 1;

		int texture_i = data->map[mapX][mapY] - 1;

		// load_textures(data); -> already beeing called at render_map3D;
		// uint32_t buffer[HEIGHT][LENGHT];
		//calculate value of tile_hit_coord -> position the ray hit the tile
		double tile_hit_X; //where exactly the wall was hit
		if (side == 0)
			tile_hit_X = data->player.play_y + perpWallDist * rayDirY;
		else
			tile_hit_X = data->player.play_x + perpWallDist * rayDirX;
		
		tile_hit_X -= floor((tile_hit_X)); //just the decimal portion

		//x coordinate on the texture
		int texture_hit_X;
		texture_hit_X = tile_hit_X * (double)data->texture_width;
		if(side == 0 && rayDirX > 0)
			texture_hit_X = data->texture_width - texture_hit_X - 1;
		if(side == 1 && rayDirY < 0)
			texture_hit_X = data->texture_width - texture_hit_X - 1;

 		double step;
 		step = 1.0 * data->texture_height / lineHeight;
		// Starting texture coordinate
		double texPos;
		texPos = (drawStart - h / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y<drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY;
			texY = (int)texPos & (data->texture_height - 1);
			texPos += step;
			unsigned long color = data->texture[texture_i][data->texture_height * texY + texture_hit_X];
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			pixel_put(&data->img, x, y, color);
		}
	}
}

void	render_map3d(t_data *data) 
{
	double	w = LENGHT;
	int		color_A = 0x777777;
	int		color_B = 0xCCCCCC;
	
	draw_background(*data, color_A, color_B);
	color_A = 0x529e35;
	color_B = 0x32aa6e;
	load_textures(data);
	render_walls(data, color_A, color_B);
}

void	render_player(t_img *img, t_player player, int l)
{
	int	x;
	int	y;
	int	x_pxl = 22 * player.play_x;
	int	y_pxl = 22 * player.play_y;

	x = x_pxl - l/2;
	while (x < x_pxl + l/2) //draw player square
	{
		y = y_pxl -l/2;
		while (y < y_pxl + l/2)
		{
			pixel_put(img, x, y, 0x0FF000);
			y++;
		}
		x++;
	}
	//draw direction point
	int	dirX_pxl = (player.play_x + player.dirX) * 22;
	int dirY_pxl = (player.play_y + player.dirY) * 22;
	int planXn = (player.play_x + player.dirX - player.cam_plane_dirX) * 22;
	int planYn = (player.play_y + player.dirY - player.cam_plane_dirY) * 22;
	int planXp = (player.play_x + player.dirX + player.cam_plane_dirX) * 22;
	int planYp = (player.play_y + player.dirY +  player.cam_plane_dirY) * 22;
	draw_line(img, (int[2]){player.play_x * 22, player.play_y * 22}, (int[2]){dirX_pxl, dirY_pxl}, 0x0000FF);
	pixel_put(img, planXn, planYn, 0x0000FF);
	pixel_put(img, planXp, planYp, 0x0000FF);
}
