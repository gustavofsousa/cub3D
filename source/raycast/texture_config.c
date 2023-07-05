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
// Em cada quadrado eu renderizo uma textura
// Preciso saber em que altura eu estou.
double	calc_tile_hit_x(t_game *game, t_ray_info *ray)
{
	double	tile_hit_x;

	tile_hit_x = 0.0;
// hor or vertcal
	if (horizontal_wall(ray))
		tile_hit_x = game->player.y + ray->dist_new_pov * ray->dir.y;
	else if (vertical_wall(ray))
		tile_hit_x = game->player.x + ray->dist_new_pov * ray->dir.x;
	tile_hit_x -= floor((tile_hit_x));
	return (tile_hit_x);
	// Retorna numero entre 0 e 1.
}

int	get_pos_y(t_game *game, t_ray_info *ray, t_img tex)
{
	int		tex_hit_x;
	double	tile_hit_x;

	tile_hit_x = calc_tile_hit_x(game, ray);
	// Em que altura da textura está.
	tex_hit_x = tile_hit_x * (double)tex.width;
	// Inverte a textura para quando estou olhando para uma mesma textura.
	if ((horizontal_wall(ray) && looking_east(ray))
		|| (vertical_wall(ray) && looking_north(ray)))
		tex_hit_x = tex.width - tex_hit_x - 1;
	return (tex_hit_x);
}




double	get_pos_x(int begin, int line_height, double step_tex)
{
	return ((begin - HEIGHT / 2 + line_height / 2) * step_tex);
}
