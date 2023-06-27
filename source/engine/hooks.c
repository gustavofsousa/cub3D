/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:42:07 by fcaetano          #+#    #+#             */
/*   Updated: 2023/06/27 09:47:00 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	walk_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = game->player.x + game->player.dir_x * game->player.speed;
	new_y = game->player.y + game->player.dir_y * game->player.speed;
	if (game->player.dir_x < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(new_x + min_dist)][(int)(game->player.y)] == 0)
		game->player.x = new_x;
	min_dist = 0.2;
	if (game->player.dir_y < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(game->player.x)][(int)(new_y + min_dist)] == 0)
		game->player.y = new_y;
}

void	walk_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	min_dist;

	min_dist = 0.2;
	new_x = game->player.x - game->player.dir_x * game->player.speed;
	new_y = game->player.y - game->player.dir_y * game->player.speed;
	if (game->player.dir_x < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(new_x - min_dist)][(int)(game->player.y)] == 0)
		game->player.x = new_x;
	min_dist = 0.2;
	if (game->player.dir_y < 0)
		min_dist *= -1;
	if (game->map.mtx_int[(int)(game->player.x)][(int)(new_y - min_dist)] == 0)
		game->player.y = new_y;
}

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

int	close_window(t_game *game)
{
	if (game->img.win)
		mlx_destroy_window(game->img.ptr, game->img.win);
	exit(0);
}
