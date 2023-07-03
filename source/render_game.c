/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:37:54 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/03 11:38:59 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	loop_hook(t_game *game)
{
	if (game->key.w_is_press + game->key.s_is_press + game->key.d_is_press
		+ game->key.ra_is_press + game->key.la_is_press + game->key.a_is_press)
	{
		if (game->key.w_is_press)
			walk_forward (game);
		if (game->key.a_is_press)
			walk_left (game);
		if (game->key.s_is_press)
			walk_backward (game);
		if (game->key.d_is_press)
			walk_right (game);
		if (game->key.ra_is_press)
			turn_right (&game->player);
		if (game->key.la_is_press)
			turn_left (&game->player);
	}
	render_map3d(game);
	if (game->key.m_is_press)
	{
    	render_map2d(game, SIZE_MMAP);
    	render_player(&game->img, game->player, 9);
	}
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	//mlx_destroy_window (game->img.ptr, game->img.win);
	return (0);
}

void	render_game(t_game *game)
{
	mlx_clear_window(game->img.ptr, game->img.win);
	render_map3d(game);
	prepare_hooks_keys(game);
	mlx_loop_hook(game->img.ptr, loop_hook, game);
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	mlx_loop(game->img.ptr);
}
