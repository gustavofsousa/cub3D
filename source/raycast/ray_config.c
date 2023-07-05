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
		ray->dist_new_pov = (ray->dist_edge.x - ray->step.x);
	else
		ray->dist_new_pov = (ray->dist_edge.y - ray->step.y);
}

void	mapping_wall_collision(t_game *game, t_ray_info *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->dist_edge.x < ray->dist_edge.y)
		{
			// Estou andnado no X.
			ray->dist_edge.x += ray->step.x;
			ray->nearest_edge.x += ray->step_square.x;
			// 0 é horizontal da parede.
			ray->side_hit = 0;
		}
		else
		{
			ray->dist_edge.y += ray->step.y;
			ray->nearest_edge.y += ray->step_square.y;
			// 1 é vertical a parede,
			ray->side_hit = 1;
		}
		if (game->map.mtx_int[ray->nearest_edge.x][ray->nearest_edge.y] > 0)
			hit = 1;
	}
}

void	get_basic_info(t_game *game, t_ray_info *ray)
{
	ray->nearest_edge.x = trunc(game->player.x);
	ray->nearest_edge.y = trunc(game->player.y);
	ray->step.x = fabs(1.0 / ray->dir.x);
	ray->step.y = fabs(1.0 / ray->dir.y);
	if (looking_west(ray))
	{
		ray->step_square.x = -1;
		ray->dist_edge.x = (game->player.x - ray->nearest_edge.x) * ray->step.x;
	}
	else if (looking_east(ray))
	{
		ray->step_square.x = 1;
		ray->dist_edge.x = (ray->nearest_edge.x + 1.0 - game->player.x) * ray->step.x;
	}
	if (looking_north(ray))
	{
		ray->step_square.y = -1;
		ray->dist_edge.y = (game->player.y - ray->nearest_edge.y) * ray->step.y;
	}
	else if (looking_south(ray))
	{
		ray->step_square.y = 1;
		ray->dist_edge.y = (ray->nearest_edge.y + 1.0 - game->player.y) * ray->step.y;
	}
}

t_double_vector	get_ray_direction(int actual_ray, t_player *player)
{
	double			point_x;
	t_double_vector	direction;

	point_x = 2.0 * actual_ray / (double)LENGHT - 1.0;
	direction.x = player->dir_x + player->cam_plane_dir_x * point_x;
	direction.y = player->dir_y + player->cam_plane_dir_y * point_x;
	return (direction);
}

void	config_ray(t_game *game, t_ray_info *ray, int actual_ray)
{
	ray->dir = get_ray_direction(actual_ray, &game->player);
	get_basic_info(game, ray);
	mapping_wall_collision(game, ray);
	fix_fish_eye(ray);
}
