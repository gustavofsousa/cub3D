#include "../include/cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (game->mlx.ptr == NULL)
		return (-1);

	return (0);
}

void    init_variables(t_game *game)
{
    // mlx
    game->mlx.height = 600;
    game->mlx.width = 600;
// Map
    game->map.height = 0;
    game->map.width = 0;
// texture
    game->texture.north = NULL;


    
}

void	setup(t_game *game)
{
    init_variables(game);
	init_mlx(game);
}