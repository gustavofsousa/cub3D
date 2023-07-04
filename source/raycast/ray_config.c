/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/04 17:05:18 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	fix_fish_eye(t_ray_info *ray)
{
	if (ray->side_hit == 0)
		ray->dist_new_pov = (ray->side.x - ray->delta.x);
	else
		ray->dist_new_pov = (ray->side.y - ray->delta.y);
}

void	mapping_wall_collision(t_game *game, t_ray_info *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->near_wall.x += ray->step.x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->near_wall.y += ray->step.y;
			ray->side_hit = 1;
		}
		if (game->map.mtx_int[ray->near_wall.x][ray->near_wall.y] > 0)
			hit = 1;
	}
}

void	get_basic_info(t_game *game, t_ray_info *ray)
{
	ray->near_wall.x = trunc(game->player.x);
	ray->near_wall.y = trunc(game->player.y);
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
	if (looking_west(ray))
	{
		ray->step.x = -1;
		ray->side.x = (game->player.x - ray->near_wall.x) * ray->delta.x;
	}
	else if (looking_east(ray))
	{
		ray->step.x = 1;
		ray->side.x = (ray->near_wall.x + 1.0 - game->player.x) * ray->delta.x;
	}
	if (looking_north(ray))
	{
		ray->step.y = -1;
		ray->side.y = (game->player.y - ray->near_wall.y) * ray->delta.y;
	}
	else if (looking_south(ray))
	{
		ray->step.y = 1;
		ray->side.y = (ray->near_wall.y + 1.0 - game->player.y) * ray->delta.y;
	}
}

t_double_vector	get_ray_direction(int actual_ray, t_player *player)
{
	double			camera_x;
	t_double_vector	direction;

	camera_x = 2.0 * actual_ray / (double)LENGHT - 1.0;
	direction.x = player->dir_x + player->cam_plane_dir_x * camera_x;
	direction.y = player->dir_y + player->cam_plane_dir_y * camera_x;
	return (direction);
}

void	config_ray(t_game *game, t_ray_info *ray, int actual_ray)
{
	ray->dir = get_ray_direction(actual_ray, &game->player);
	get_basic_info(game, ray);
	mapping_wall_collision(game, ray);
	fix_fish_eye(ray);
}
