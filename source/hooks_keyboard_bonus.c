/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:35:58 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/07/05 11:36:21 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65362 || keycode == 119)
		game->key.w_is_press = 1;
	if (keycode == 97)
		game->key.a_is_press = 1;
	if (keycode == 65364 || keycode == 115)
		game->key.s_is_press = 1;
	if (keycode == 100)
		game->key.d_is_press = 1;
	if (keycode == 65363)
		game->key.ra_is_press = 1;
	if (keycode == 65361)
		game->key.la_is_press = 1;
	if (keycode == 109)
	{
		if (game->key.m_is_press)
			game->key.m_is_press = 0;
		else
			game->key.m_is_press = 1;
	}
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 65362 || keycode == 119)
		game->key.w_is_press = 0;
	if (keycode == 97)
		game->key.a_is_press = 0;
	if (keycode == 65364 || keycode == 115)
		game->key.s_is_press = 0;
	if (keycode == 100)
		game->key.d_is_press = 0;
	if (keycode == 65363)
		game->key.ra_is_press = 0;
	if (keycode == 65361)
		game->key.la_is_press = 0;
	return (0);
}

void	prepare_hooks_keys(t_game *game)
{
	mlx_hook(game->img.win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->img.win, 3, 1L << 1, handle_key_release, game);
	mlx_hook(game->img.win, 17, 0, close_window, game);
}
