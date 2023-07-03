/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:42:07 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/03 16:07:27 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_vectors(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = (*x) * cos(angle) - (*y) * sin(angle);
	*y = old_x * sin(angle) + (*y) * cos(angle);
}

void	turn_left(t_player *player)
{
	rotate_vectors(&(player->dir_x),
		&(player->dir_y),
		-player->rot_speed);
	rotate_vectors(&(player->cam_plane_dir_x),
		&(player->cam_plane_dir_y),
		-player->rot_speed);
}

void	turn_right(t_player *player)
{
	rotate_vectors(&(player->dir_x),
		&(player->dir_y),
		player->rot_speed);
	rotate_vectors(&(player->cam_plane_dir_x),
		&(player->cam_plane_dir_y),
		player->rot_speed);
}
