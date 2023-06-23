/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/22 19:23:43 by gustavosous      ###   ########.fr       */
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

void	print_mtx(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			printf("%d", game->map.mtx_int[i][j]);
		}
		printf("\n");
	}
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
