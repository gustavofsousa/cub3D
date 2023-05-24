#include "../include/cub3d.h"

void	init_game(t_game *game, t_img img)
{
	game->canvas = img.addr;
}

int	init_mlx(t_img *img)
{
	img->ptr = mlx_init();
	if (img->ptr == NULL)
		return (-1);
	img->win = mlx_new_window(img->ptr, LENGHT, HEIGHT, "cub3D");
	if (img->win == NULL)
		return (-1);
	img->img = mlx_new_image(img->ptr, LENGHT, HEIGHT);
	if (img->img == NULL)
		return (-1);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	img->line_len /= 4;
	//add_mlx_hook(fdf);
	//draw_win(fdf);
	mlx_loop(img->ptr);
	return (0);
}

void	setup(t_game game, t_img img)
{
	init_mlx(&img);
	init_game(&game, img);

}

int	main(int argc, char **argv)
{
//	t_game	game;
//	t_img	img;

(void)argc;
(void)argv;
//	setup(&game, &img);
	//interpretate_map(&game);
	//render_game(&game);
	ft_putstr_fd("Guten morgen", 1);
}
