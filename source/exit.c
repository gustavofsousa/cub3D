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

void	free_texture(t_texture texture)
{
	mlx_destroy_image(texture.north.ptr, texture.north.img);
	mlx_destroy_image(texture.south.ptr, texture.south.img);
	mlx_destroy_image(texture.east.ptr, texture.east.img);
	mlx_destroy_image(texture.west.ptr, texture.west.img);
}

int	close_window(t_game *game)
{
	free_map(game);
	free_texture(game->texture);
	if (game->img.win)
		mlx_destroy_window(game->img.ptr, game->img.win);
	if (game->img.img)
		mlx_destroy_image(game->img.ptr, game->img.img);
	mlx_destroy_display(game->img.ptr);
	free(game->img.ptr);
	exit(0);
}

void	exit_game(char *message, t_game *game)
{
	if (message)
		ft_putendl_fd(message, 2);
	free_map(game);
	exit(0);
}
