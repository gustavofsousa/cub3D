/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 16:09:13 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	walk_right(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = player->x + player->cam_plane_dir_x * player->speed;
	new_y = player->y + player->cam_plane_dir_y * player->speed;
	if (player->cam_plane_dir_y < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(new_x + min_dist)]
					[(int)(player->y)] == 0)
		player->x = new_x;
	min_dist = 0.2;
	if (player->cam_plane_dir_x < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(player->x)]
					[(int)(new_y + min_dist)] == 0)
		player->y = new_y;
}

void	walk_left(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = player->x - player->cam_plane_dir_x * player->speed;
	new_y = player->y - player->cam_plane_dir_y * player->speed;
	if (player->cam_plane_dir_x < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(new_x - min_dist)]
					[(int)(player->y)] == 0)
		player->x = new_x;
	min_dist = 0.2;
	if (player->cam_plane_dir_y < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(player->x)]
					[(int)(new_y - min_dist)] == 0)
		player->y = new_y;
}

void	walk_forward(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = player->x + player->dir_x * player->speed;
	new_y = player->y + player->dir_y * player->speed;
	if (player->dir_x < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(new_x + min_dist)][(int)(player->y)] == 0)
		player->x = new_x;
	min_dist = 0.2;
	if (player->dir_y < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(player->x)]
					[(int)(new_y + min_dist)] == 0)
		player->y = new_y;
}

void	walk_backward(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = player->x - player->dir_x * player->speed;
	new_y = player->y - player->dir_y * player->speed;
	if (player->dir_x < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(new_x - min_dist)]
					[(int)(player->y)] == 0)
		player->x = new_x;
	min_dist = 0.2;
	if (player->dir_y < 0)
		min_dist *= -1;
	if (map->mtx_int[(int)(player->x)]
					[(int)(new_y - min_dist)] == 0)
		player->y = new_y;
}
