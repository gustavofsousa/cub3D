#include "../include/cub3d.h"





int	main(int argc, char **argv)
{
	t_game	game;

(void)argc;
(void)argv;
	setup(&game);
	//interpretate_map(&game);
	//validate_map(game);
	render_game(&game);
	ft_putstr_fd("Guten morgen", 1);
}
