#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	int	i;

	if (game->map.mtx)
	{
		i = -1;
		while (game->map.mtx[++i])
			free(game->map.mtx[i]);
		free(game->map.mtx);
	}
}

void	exit_game(t_game *game)
{
	free_map(game);
	// free_texture(game);
	// free_mlx(game);
	exit(0);
}



int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		setup(&game);
		interpretate_map(&game, argv[1]);
		//validate_map(game);
		render_game(&game);
		ft_putstr_fd("Guten morgen", 1);
		return (0);
	}
	ft_putendl_fd("Usage: ./cub3D <map.cub>", 1);
	return (1);

}
