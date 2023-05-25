#include "../include/cub3d.h"





int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	setup(&game);
	interpretate_map(&game, argv[1]);
	//validate_map(game);
	render_game(&game);
	ft_putstr_fd("Guten morgen", 1);
	return (0);
}
