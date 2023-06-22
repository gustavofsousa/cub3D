/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/22 16:15:54 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	if (game && game->map.mtx)
		free_matrix(game->map.mtx);
}

void	exit_game(char *message, t_game *game)
{
	if (message)
		ft_putendl_fd(message, 2);
	free_map(game);
	// free_texture(game);
	// free_mlx(game);
	// destroy mlx window and image ??
	exit(0);
}

void	print_mtx(char **mtx)
{
	int	i;

	i = -1;
	while (mtx[++i])
		printf("%s\n", mtx[i]);
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
		exit_game(NULL, &game);
	}
	ft_putendl_fd("Usage: ./cub3D <map.cub>", 1);
	return (1);
}
