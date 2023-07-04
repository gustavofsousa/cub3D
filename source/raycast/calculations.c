/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:38 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/04 16:03:20 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
* 1. Calculate the lowest pixel to draw
* 2. Calculate the highest pixel to draw
* 3. Calculate the step to move in the texture
* 4. Calculate the initial position in the texture
* 5. Draw the pixels
*/
void	calc_wall_hit(t_game *game, t_ray_info *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map_hit.x += ray->step.x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map_hit.y += ray->step.y;
			ray->side_hit = 1;
		}
		if (game->map.mtx_int[ray->map_hit.x][ray->map_hit.y] > 0)
			hit = 1;
	}
}

/*
* 1. Calculate the ray info
* 2. Calculate the wall hit
* 3. Calculate the perp wall dist
*/
void	calc_ray_info(t_game *game, t_ray_info *ray)
{
	ray->map_hit.x = trunc(game->player.x);
	ray->map_hit.y = trunc(game->player.y);
	ray->delta.x = fabs(1.0 / ray->dir.x);
	ray->delta.y = fabs(1.0 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (game->player.x - ray->map_hit.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map_hit.x + 1.0 - game->player.x) * ray->delta.x;
	}
	if (looking_north(ray))
	{
		ray->step.y = -1;
		ray->side.y = (game->player.y - ray->map_hit.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map_hit.y + 1.0 - game->player.y) * ray->delta.y;
	}
}

/*
* 1. Calculate the ray info
* 2. Calculate the wall hit
* 3. Calculate the perp wall dist
*/
void	calc_perp_wall_dist(t_game *game, t_ray_info *ray)
{
	calc_ray_info(game, ray);
	calc_wall_hit(game, ray);
	if (ray->side_hit == 0)
		ray->perp_wall_dist = (ray->side.x - ray->delta.x);
	else
		ray->perp_wall_dist = (ray->side.y - ray->delta.y);
}

/*
* 1. Calculate the ray direction
* 2. Calculate the delta distance
* 3. Calculate the step and the side
* 4. Calculate the wall hit
* 5. Calculate the perp wall dist
*/
t_double_vector	calc_ray_dir(int x, t_player *player)
{
	double			camera_x;
	t_double_vector	ray_dir;

	camera_x = 2.0 * x / (double)LENGHT - 1.0;
	ray_dir.x = player->dir_x + player->cam_plane_dir_x * camera_x;
	ray_dir.y = player->dir_y + player->cam_plane_dir_y * camera_x;
	return (ray_dir);
}
