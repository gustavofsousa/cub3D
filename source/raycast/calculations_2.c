/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:55 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/04 16:03:17 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	calc_highest_pixel(int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	return (draw_end);
}

int	calc_lowest_pixel(int line_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

/*
* 1. Calculate the step to move in the texture
* 2. Calculate the initial position in the texture
* 3. Draw the pixels
*/
double	calc_tile_hit_x(t_game *game, t_ray_info *ray)
{
	double	tile_hit_x;

	if (ray->side_hit == 0)
		tile_hit_x = game->player.y + ray->perp_wall_dist * ray->dir.y;
	else
		tile_hit_x = game->player.x + ray->perp_wall_dist * ray->dir.x;
	tile_hit_x -= floor((tile_hit_x));
	return (tile_hit_x);
}

/*
* 1. Calculate the texture hit x
* 2. Calculate the texture hit y
* 3. Draw the pixels
*/
int	calc_tex_hit_x(t_game *game, t_ray_info *ray, t_img tex)
{
	int		tex_hit_x;
	double	tile_hit_x;

	tile_hit_x = calc_tile_hit_x(game, ray);
	tex_hit_x = tile_hit_x * (double)tex.width;
	if ((ray->side_hit == 0 && looking_east(ray))
		|| (ray->side_hit == 1 && looking_north(ray)))
		tex_hit_x = tex.width - tex_hit_x - 1;
	return (tex_hit_x);
}
