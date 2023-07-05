/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:55 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/04 18:26:01 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned long	tex_color(t_img tex, int tex_pos, int tex_scale_tile)
{
	int	tex_y;
	int	*texture;

	texture = (int *) tex.addr;
	tex_y = (int)tex_pos & (tex.height - 1);
	return (texture[tex.height * tex_y + tex_scale_tile]);
}

t_img	choose_texture(t_game *game, t_ray_info *ray)
{
	if (vertical_wall(ray))
	{
		if (looking_north(ray))
			return (game->texture.north);
		if (looking_south(ray))
			return (game->texture.south);
	}
	else if (horizontal_wall(ray))
	{
		if (looking_east(ray))
			return (game->texture.east);
		if (looking_west(ray))
			return (game->texture.west);
	}
	return (game->texture.north);
}

double	calc_scale_tile(t_game *game, t_ray_info *ray)
{
	double	scale_tile;

	scale_tile = 0.0;
	if (horizontal_wall(ray))
		scale_tile = game->player.y + ray->dist_new_pov * ray->dir.y;
	else if (vertical_wall(ray))
		scale_tile = game->player.x + ray->dist_new_pov * ray->dir.x;
	scale_tile -= floor((scale_tile));
	return (scale_tile);
}

int	get_scale_y(t_game *game, t_ray_info *ray, t_img tex)
{
	int		tex_scale_tile;
	double	scale_tile;

	scale_tile = calc_scale_tile(game, ray);
	tex_scale_tile = scale_tile * (double)tex.width;
	if ((horizontal_wall(ray) && looking_east(ray))
		|| (vertical_wall(ray) && looking_north(ray)))
		tex_scale_tile = tex.width - tex_scale_tile - 1;
	return (tex_scale_tile);
}

double	get_scale_x(int begin, int line_height, double step_tex)
{
	return ((begin - HEIGHT / 2 + line_height / 2) * step_tex);
}
