/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 12:32:56 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_tiny_square(t_img *img, int x0, int y0, int color)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	max_x = x0 + SIZE_MMAP;
	max_y = y0 + SIZE_MMAP;
	x = x0;
	while (x < max_x)
	{
		y = y0;
		while (y < max_y)
		{
			pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_map2d(t_game *game, int square_sz)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.mtx_int[i][j] == 1)
				draw_tiny_square(&game->img, i * square_sz, j * square_sz,
					COLOR_FLOOR_MMAP);
			else
				draw_tiny_square(&game->img, i * square_sz, j * square_sz,
					COLOR_WALL_MMAP);
		}
	}
}
