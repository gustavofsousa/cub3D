/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/04 18:18:43 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_highest_pixel(int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	return (draw_end);
}

int	get_lowest_pixel(int line_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

void	paint_column(t_game *game, t_ray_info *ray, int actual_ray)
{
	int		line_height;
	int		draw_limits[2];
	double	step_tex;
	double	tex_pos_x;
	int		tex_pos_y;
	t_img	tex;

	line_height = HEIGHT / ray->dist_new_pov;
	draw_limits[0] = get_lowest_pixel(line_height);
	draw_limits[1] = get_highest_pixel(line_height);

	tex = choose_texture(game, ray);
	step_tex = (1.0 * tex.height) / line_height;

	// Cada x da tela está relacionado a um x da textura.
	tex_pos_x = get_pos_x(draw_limits[0], line_height, step_tex);
	tex_pos_y = get_pos_y(game, ray, tex);
	
	while (draw_limits[0] <= draw_limits[1])
	{
		if (ray->side_hit == 1)
			pixel_put(&game->img, actual_ray, draw_limits[0],
				(tex_color(tex, tex_pos_x, tex_pos_y) >> 1) & 8355711);
		else
			pixel_put(&game->img, actual_ray, draw_limits[0],
				tex_color(tex, tex_pos_x, tex_pos_y));
		tex_pos_x += step_tex;
		draw_limits[0]++;
	}
}

void	paint_walls(t_game *game)
{
	int			actual_ray;
	t_ray_info	ray;

	actual_ray = 0;
	while (actual_ray < LENGHT)
	{
		config_ray(game, &ray, actual_ray);
		paint_column(game, &ray, actual_ray);
		actual_ray++;
	}
}
