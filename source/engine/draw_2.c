/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:47 by fcaetano          #+#    #+#             */
/*   Updated: 2023/07/03 16:36:39 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
