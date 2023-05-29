#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	free_matrix(game->map.mtx);
}

void	exit_game(char *message, t_game *game)
{
	if (message)
		ft_putendl_fd(message, 2);
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
		validate_map(&game);
		//render_game(&game);
		ft_putendl_fd("Guten morgen", 1);
		exit_game(NULL, &game);
		}
	ft_putendl_fd("Usage: ./cub3D <map.cub>", 1);
	return (1);

}
