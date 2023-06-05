#include "../include/cub3d.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	render_map2d(t_game *game)
// {
// 	const int map[LENGHT][HEIGHT] = {
// 		{1, 1, 1, 1, 1},
// 		{1, 0, 0, 0, 1},
// 		{1, 1, 0, 0, 1},
// 		{1, 0, 0, 1, 1},
// 		{1, 0, 0, 0, 1},
// 		{1, 1, 1, 1, 1}
// 	};

// 	pixel_put(game, 0, 0, 0xFFFFFF);
// }

void render_game()
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
															 &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}