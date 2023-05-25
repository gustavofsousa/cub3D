#include "../include/cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (game->mlx.ptr == NULL)
		return (-1);

	return (0);
}

void	setup(t_game *game)
{
	init_mlx(game);
}