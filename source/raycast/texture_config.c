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

unsigned long	tex_color(t_img tex, int tex_pos, int tex_hit_x)
{
	int	tex_y;
	int	*texture;

	texture = (int *) tex.addr;
	tex_y = (int)tex_pos & (tex.height - 1);
	return (texture[tex.height * tex_y + tex_hit_x]);
}

t_img	choose_texture(t_game *game, t_ray_info *ray)
{
	if (ray->side_hit)
	{
		if (looking_north(ray))
			return (game->texture.north);
		if (looking_south(ray))
			return (game->texture.south);
	}
	else
	{
		if (looking_east(ray))
			return (game->texture.east);
		if (looking_west(ray))
			return (game->texture.west);
	}
	return (game->texture.north);
}

double	calc_tile_hit_x(t_game *game, t_ray_info *ray)
{
	double	tile_hit_x;

	if (ray->side_hit == 0)
		tile_hit_x = game->player.y + ray->dist_new_pov * ray->dir.y;
	else
		tile_hit_x = game->player.x + ray->dist_new_pov * ray->dir.x;
	tile_hit_x -= floor((tile_hit_x));
	return (tile_hit_x);
}

int	get_pos_y(t_game *game, t_ray_info *ray, t_img tex)
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

double	get_pos_x(int begin, int line_height, double step_tex)
{
	return ((begin - HEIGHT / 2 + line_height / 2) * step_tex);
}
