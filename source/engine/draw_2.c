/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:47 by fcaetano          #+#    #+#             */
/*   Updated: 2023/06/27 09:39:48 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_x_line(t_game *game, t_ray_info *ray, int line_height, int x)
{
	int		draw_limits[2];
	double	step_tex;
	double	tex_pos;
	int		tex_hit_x;
	t_img	tex;

	tex = def_tex(game, ray);
	tex_hit_x = calc_tex_hit_x(game, ray, tex);
	draw_limits[0] = calc_lowest_pixel(line_height);
	draw_limits[1] = calc_highest_pixel(line_height);
	step_tex = 1.0 * tex.height / line_height;
	tex_pos = (draw_limits[0] - HEIGHT / 2 + line_height / 2) * step_tex;
	while (draw_limits[0] <= draw_limits[1])
	{
		tex_pos += step_tex;
		if (ray->side_hit == 1)
			pixel_put(&game->img, x, draw_limits[0],
				(tex_color(game, tex, tex_pos, tex_hit_x) >> 1) & 8355711);
		else
			pixel_put(&game->img, x, draw_limits[0],
				tex_color(game, tex, tex_pos, tex_hit_x));
		draw_limits[0]++;
	}
}

void	draw_background(t_game game)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < LENGHT)
	{
		y = 0;
		color = game.texture.ceiling;
		while (y < HEIGHT)
		{
			if (y == HEIGHT / 2)
				color = game.texture.floor;
			pixel_put(&game.img, x, y, color);
			y++;
		}
		x++;
	}
}
