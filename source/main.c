/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 12:08:46 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	if (game && game->map.mtx)
		ft_free_matrix(game->map.mtx);
	if (game && game->map.mtx_int)
		free_matrix_int(game);
}

void	exit_game(char *message, t_game *game)
{
	if (message)
		ft_putendl_fd(message, 2);
	free_map(game);
	exit(0);
}

int	close_window(t_game *game)
{
	if (game->img.win)
		mlx_destroy_window(game->img.ptr, game->img.win);
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
