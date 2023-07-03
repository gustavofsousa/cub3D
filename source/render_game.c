/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:37:54 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/03 15:30:54 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_minimap(t_game *game)
{
	if (game->key.m_is_press)
	{
		draw_map2d(game, SIZE_MMAP);
		draw_miniplayer(&game->img, game->player, 9);
	}
}

void	render_map3d(t_game *game)
{
	draw_background(*game);
	raycast(game);
}


void	move_player(t_game *game)
{
	if (game->key.w_is_press)
		walk_forward(game);
	if (game->key.a_is_press)
		walk_left(game);
	if (game->key.s_is_press)
		walk_backward(game);
	if (game->key.d_is_press)
		walk_right(game);
	if (game->key.ra_is_press)
		turn_right(&game->player);
	if (game->key.la_is_press)
		turn_left(&game->player);
}


int	playing_the_game(t_game *game)
{
	move_player(game);
	render_map3d(game);
	render_minimap(game);
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	//mlx_destroy_window (game->img.ptr, game->img.win);
	return (0);
}

void	render_game(t_game *game)
{
	prepare_hooks_keys(game);
	mlx_loop_hook(game->img.ptr, playing_the_game, game);
	mlx_loop(game->img.ptr);
}
