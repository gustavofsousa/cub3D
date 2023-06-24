/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/22 18:50:162 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	choose_direction_y(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'W')
		return (0);
	else if (c == 'N')
		return (-1);
	else if (c == 'S')
		return (1);
  return (0);
}

int	choose_direction_x(char c)
{
	if (c == 'E')
		return (1);
	else if (c == 'W')
		return (-1);
	else if (c == 'N')
		return (0);
	else if (c == 'S')
		return (0);
  return (0);
}

int	is_valid_player(char map_cell)
{
	if (ft_strchr("NSEW", map_cell) != 0)
		return (1);
	return (0);
}

void	setup_camera_plane(t_game *game, char spawn_direction)
{
	if (spawn_direction == 'W' || spawn_direction == 'E')
	{
		game->player.cam_plane_dir_x = 0;
		game->player.cam_plane_dir_y = 0.66;
		if (spawn_direction == 'W')
			game->player.cam_plane_dir_y *= -1;
	}
	if (spawn_direction == 'N' || spawn_direction == 'S')
	{
		game->player.cam_plane_dir_x = 0.66;
		game->player.cam_plane_dir_y = 0;
		if (spawn_direction == 'S')
			game->player.cam_plane_dir_x *= -1;
	}
}

void	validate_player(t_game *game)
{
	int	i;
	int	j;
	int	qtd_player;

	qtd_player = 0;
	i = -1;
	while (game->map.mtx[++i])
	{
		j = -1;
		while (game->map.mtx[i][++j])
		{
			if (is_valid_player(game->map.mtx[i][j]))
			{
				game->player.x = j;
				game->player.y = i;
				game->player.dir_x = choose_direction_x(game->map.mtx[i][j]);
				game->player.dir_y = choose_direction_y(game->map.mtx[i][j]);
				setup_camera_plane(game, game->map.mtx[i][j]);
				qtd_player++;
			}
		}
	}
	if (qtd_player != 1)
		exit_game("Incorrect number of player", game);
}
