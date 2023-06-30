/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:42:07 by fcaetano          #+#    #+#             */
/*   Updated: 2023/06/29 17:17:25 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	walk_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = game->player.x + game->player.cam_plane_dir_x * game->player.speed;
	new_y = game->player.y + game->player.cam_plane_dir_y * game->player.speed;
	if (game->player.cam_plane_dir_y < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(new_x + min_dist)][(int)(game->player.y)] == 0)
		game->player.x = new_x;
	min_dist = 0.2;
	if (game->player.cam_plane_dir_x < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(game->player.x)][(int)(new_y + min_dist)] == 0)
		game->player.y = new_y;
}

void	walk_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = game->player.x - game->player.cam_plane_dir_x * game->player.speed;
	new_y = game->player.y - game->player.cam_plane_dir_y * game->player.speed;
	if (game->player.cam_plane_dir_x < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(new_x - min_dist)][(int)(game->player.y)] == 0)
		game->player.x = new_x;
	min_dist = 0.2;
	if (game->player.cam_plane_dir_y < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(game->player.x)][(int)(new_y - min_dist)] == 0)
		game->player.y = new_y;
}