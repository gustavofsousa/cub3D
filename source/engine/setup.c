#include "../../include/cub3d.h"

int map[15][20] = {
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
		
void	setup_map(t_data *dat)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	dat->map =  malloc(dat->n_columns * sizeof(int*));
	while (x < dat->n_columns)
	{
		dat->map[x] = malloc(dat->n_rows * sizeof(int));
		x++;
	}
	x = 0;
	while (x < dat->n_columns)
	{
		y = 0;
		while (y < dat->n_rows)
		{
			dat->map[x][y] =  map[x][y];
			y++;
		}
		x++;
	}
}

void	setup_data(t_data *dat)
{
	dat->player.play_x = 5;
	dat->player.play_y = 17;
	dat->player.cam_plane_dirX = 0;
	dat->player.cam_plane_dirY = 0.66;
	dat->player.dirX = 1;
	dat->player.dirY = 0;
	dat->player.speed = 0.005;
	dat->player.rot_speed = 0.003;
	dat->key.w_is_press = 0;
	dat->key.a_is_press = 0;
	dat->key.s_is_press = 0;
	dat->key.d_is_press = 0;
	dat->n_rows = 20;
	dat->n_columns = 15;
	setup_map(dat);
}

void	setup_game(t_img *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, LENGHT, HEIGHT, "cub3D");
	img->img = mlx_new_image(img->mlx, LENGHT, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}