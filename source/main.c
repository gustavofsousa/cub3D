/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 10:30:36 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	if (game && game->map.mtx)
		free_matrix(game->map.mtx);
	if (game && game->map.mtx_int)
		free_matrix_int(game);
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
		transform_map_int(&game);
		render_game(&game);
		exit_game(NULL, &game);
	}
	ft_putendl_fd("Usage: ./cub3D <map.cub>", 1);
	return (1);
}
