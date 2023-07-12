/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 11:38:32 by gde-jesu         ###   ########.fr       */
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

void	paint_column(t_game *game, t_ray_info *ray, int a_ray, int line_height)
{
	int		draw_limits[2];
	double	step_tex;
	double	tex_scale_x;
	int		tex_scale_y;
	t_img	tex;

	draw_limits[0] = get_lowest_pixel(line_height);
	draw_limits[1] = get_highest_pixel(line_height);
	tex = choose_texture(game, ray);
	step_tex = (1.0 * tex.height) / line_height;
	tex_scale_x = get_scale_x(draw_limits[0], line_height, step_tex);
	tex_scale_y = get_scale_y(game, ray, tex);
	while (draw_limits[0] <= draw_limits[1])
	{
			pixel_put(&game->img, a_ray, draw_limits[0],
				tex_color(tex, tex_scale_x, tex_scale_y));
		tex_scale_x += step_tex;
		draw_limits[0]++;
	}
}

void	paint_walls(t_game *game)
{
	int			line_height;
	int			actual_ray;
	t_ray_info	ray;

	actual_ray = 0;
	while (actual_ray < LENGHT)
	{
		config_ray(game, &ray, actual_ray);
		line_height = HEIGHT / ray.dist_new_pov;
		paint_column(game, &ray, actual_ray, line_height);
		actual_ray++;
	}
}
