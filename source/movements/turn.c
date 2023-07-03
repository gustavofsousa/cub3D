/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:42:07 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/03 15:30:59 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	turn_left(t_player *player)
{
	double	old_x;

	old_x = (player->dir_x);
	player->dir_x = player->dir_x * cos(-player->rot_speed)
		- player->dir_y * sin(-player->rot_speed);
	player->dir_y = old_x * sin(-player->rot_speed)
		+ player->dir_y * cos(-player->rot_speed);
	old_x = player->cam_plane_dir_x;
	player->cam_plane_dir_x = player->cam_plane_dir_x * cos(-player->rot_speed)
		- player->cam_plane_dir_y * sin(-player->rot_speed);
	player->cam_plane_dir_y = old_x * sin(-player->rot_speed)
		+ player->cam_plane_dir_y * cos(-player->rot_speed);
}

void	turn_right(t_player *player)
{
	double	old_x;

	old_x = (player->dir_x);
	player->dir_x = player->dir_x * cos(player->rot_speed)
		- player->dir_y * sin(player->rot_speed);
	player->dir_y = old_x * sin(player->rot_speed)
		+ player->dir_y * cos(player->rot_speed);
	old_x = player->cam_plane_dir_x;
	player->cam_plane_dir_x = player->cam_plane_dir_x * cos(player->rot_speed)
		- player->cam_plane_dir_y * sin(player->rot_speed);
	player->cam_plane_dir_y = old_x * sin(player->rot_speed)
		+ player->cam_plane_dir_y * cos(player->rot_speed);
}
