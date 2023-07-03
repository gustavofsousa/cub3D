/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 18:43:37 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned long	tex_color(t_img tex, int tex_pos, int tex_hit_x)
{
	int	tex_y;
	int	*texture;

	texture = (int *) tex.addr;
	tex_y = (int)tex_pos & (tex.height - 1);
	return (texture[tex.height * tex_y + tex_hit_x]);
}

t_img	def_tex(t_game *game, t_ray_info *ray)
{
	if (ray->side_hit)
	{
		if (ray->dir.y < 0)
			return (game->texture.north);
		return (game->texture.south);
	}
	else
	{
		if (ray->dir.x > 0)
			return (game->texture.east);
		return (game->texture.west);
	}
}

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
				(tex_color(tex, tex_pos, tex_hit_x) >> 1) & 8355711);
		else
			pixel_put(&game->img, x, draw_limits[0],
				tex_color(tex, tex_pos, tex_hit_x));
		draw_limits[0]++;
	}
}

void	paint_walls(t_game *game)
{
	int			x;
	int			line_height;
	t_ray_info	ray;

	x = 0;
	while (x < LENGHT)
	{
		ray.dir = calc_ray_dir(x, &game->player);
		calc_perp_wall_dist(game, &ray);
		line_height = (int)(HEIGHT / ray.perp_wall_dist);
		draw_x_line(game, &ray, line_height, x);
		x++;
	}
}
