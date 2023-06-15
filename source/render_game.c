#include "../include/cub3d.h"

int		map[15][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


// int map[ROW][COLUMN]=
// {
//   {1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,1},
//   {1,1,1,0,0,0,0,1},
//   {1,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1}
// };

void	init_game(t_img *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, LENGHT, HEIGHT, "cub3D");
	img->img = mlx_new_image(img->mlx, LENGHT, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->img.mlx, data->img.mlx_win);
		exit(0);
	}
	return (0);
}

void draw_vertical_line(t_img *img, int x, int y0, int yf, int color)
{
	while (y0 <= yf)
	{
		pixel_put(img, x, y0, color);
		y0++;
	}
}


void	render_map3d(t_data *data) {

	data->player.play_x = 7;
	data->player.play_y = 10;

	double	dirX = -1;
	double	dirY = 0;

	double	planeX = 0;
	double	planeY = 0.66;

	int		w = LENGHT; //INICIALIZAARR CORRETAMENTE
	int		color = 0x529e35;

	for(int x = 0; x < 50; x++)
	{
		printf("\n%i\n", x);
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		printf("camerax:%f\n", cameraX);

		double rayDirX = dirX + planeX * cameraX;
		printf("rayDirX:%f ", rayDirX);
		double rayDirY = dirY + planeY * cameraX;
		printf("rayDirY:%f\n", rayDirY);

		int mapX = (int)data->player.play_x;
		int mapY = (int)data->player.play_y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX); //C has infinity, so theres is no need to check rayDir and assign 1e30
		double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY); //C has infinity, so theres is no need to check rayDir and assign 1e30
		
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
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

		//perform DDA
		printf("stepX:%i stepY:%i\n", stepX, stepY);
		while (hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
		printf("sideDistX:%f sideDistY:%f , deltaDistX:%f destaDistY:%f\n", sideDistX, sideDistY, deltaDistX, deltaDistY); 
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
			if (map[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = (sideDistX + deltaDistX);
    	else
			perpWallDist = (sideDistY + deltaDistY);
		
		
		printf("wall hit:%i,%i perpWallDist:%f", mapX, mapY, perpWallDist);
		//Calculate height of line to draw on screen
		int h = HEIGHT; //h is the height in pixels of the screen, that way we transform from map to pixel coordinates
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) //guarantee not to draw outside the screen/image
			drawStart = 0;
		
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) //guarantee not to draw outside the screen/image
			drawEnd = h - 1;

		// printf("x:%i, drawStart:%i, drawEnd: %i\n", x, drawStart, drawEnd);
		if (side == 0)
			draw_vertical_line(&data->img, x, drawStart, drawEnd, color);
		else	
			draw_vertical_line(&data->img, x, drawStart, drawEnd, 0x32aa6e);
	}
}

void	render_game(void)
{
	t_data data;

	init_game(&data.img);
	render_map3d(&data);
	// draw_vertical_line(&data.img, LENGHT-1, 0, HEIGHT/3, 0xFF0000);
	// draw_line(&data.img, (int[2]){0,0}, (int[2]){100,100});
	mlx_key_hook(data.img.mlx_win, key_hooks, &data);
	mlx_put_image_to_window(data.img.mlx, data.img.mlx_win, data.img.img, 0, 0);
	mlx_loop(data.img.mlx);
}