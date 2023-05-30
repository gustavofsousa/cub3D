#include "../../include/cub3d.h"

void	game_loop(t_game *game)
{
	(void)game;
	//update_player(game);
	//render_scene(game);
}

int	init_game(t_game *game)
{	
	game->mlx.win = mlx_new_window(game->mlx.ptr, LENGHT, HEIGHT, "cub3D");
	if (game->mlx.win == NULL)
		return (-1);
	game->mlx.img = mlx_new_image(game->mlx.ptr, LENGHT, HEIGHT);
	if (game->mlx.img== NULL)
		return (-1);
	game->mlx.addr = (int *)mlx_get_data_addr(game->mlx.img, &game->mlx.bpp, &game->mlx.line_len, &game->mlx.endian);
	game->mlx.line_len /= 4;

	
    return (0);
}

void    render_game(t_game *game)
{
	//add__hook(game);
    init_game(game);
	//game_loop(game);
	mlx_loop(game->mlx.ptr);
	game->canvas = game->mlx.addr;
	}