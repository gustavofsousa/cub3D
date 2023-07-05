/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 18:41:29 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	render_minimap(t_game *game)
{
	if (game->key.m_is_press)
	{
		draw_map2d(game, SIZE_MMAP);
		draw_miniplayer(&game->img, game->player, 9);
	}
}

void	raycast(t_game *game)
{
	draw_background(*game);
	paint_walls(game);
}

void	move_player(t_game *game)
{
	if (game->key.w_is_press)
		walk_forward(&game->player, &game->map);
	if (game->key.a_is_press)
		walk_left(&game->player, &game->map);
	if (game->key.s_is_press)
		walk_backward(&game->player, &game->map);
	if (game->key.d_is_press)
		walk_right(&game->player, &game->map);
	if (game->key.ra_is_press)
		turn_right(&game->player);
	if (game->key.la_is_press)
		turn_left(&game->player);
}

int	playing_the_game(t_game *game)
{
	move_player(game);
	raycast(game);
	render_minimap(game);
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	return (0);
}

void	render_game(t_game *game)
{
	create_window_mlx(game);
	prepare_hooks_keys(game);
	mlx_loop_hook(game->img.ptr, playing_the_game, game);
	mlx_loop(game->img.ptr);
}
