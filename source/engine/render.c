#include "../../include/cub3d.h"

void render_map2d(t_data *data, int square_sz)
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
			if (data->map[i][j]  == 1)
				draw_square(&data->img, i * square_sz, j * square_sz, 0xFF0000, 22);
			else
 				draw_square(&data->img, i * square_sz, j * square_sz, 0xFFF000, 22);
			j++;
		}
		i++;
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

		// printf("x:%i, drawStart:%i, drawEnd: %i\n", x, drawStart, drawEnd);
		if (side == 0)
			draw_vertical_line(&data->img, x, drawStart, drawEnd, color_A);
		else	
			draw_vertical_line(&data->img, x, drawStart, drawEnd, color_B);
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