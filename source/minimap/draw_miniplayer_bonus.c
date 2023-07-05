/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_miniplayer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 11:40:57 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_line(t_img *img, int i[2], int f[2], int color)
{
	int	dist_x;
	int	dist_y;

	dist_x = ft_abs(f[0] - i[0]);
	dist_y = ft_abs(f[1] - i[1]);
	if (dist_x >= dist_y)
	{
		if (i[0] < f[0])
			bresenham_x(img, i, f, color);
		else
			bresenham_x(img, f, i, color);
	}
	else
	{
		if (i[1] < f[1])
			bresenham_y(img, i, f, color);
		else
			bresenham_y(img, f, i, color);
	}
}

void	draw_player_square(t_img *img, t_player player, int l)
{
	int	x;
	int	y;
	int	y_pxl;
	int	x_pxl;

	x_pxl = SIZE_MMAP * player.x;
	y_pxl = SIZE_MMAP * player.y;
	x = x_pxl - l / 2;
	while (x < x_pxl + l / 2)
	{
		y = y_pxl - l / 2;
		while (y < y_pxl + l / 2)
		{
			pixel_put(img, x, y, COLOR_PLAYER_MMP);
			y++;
		}
		x++;
	}
}

void	draw_miniplayer(t_img *img, t_player player, int l)
{
	draw_player_square(img, player, l);
	player.dirx_pxl = (player.x + player.dir_x) * SIZE_MMAP;
	player.diry_pxl = (player.y + player.dir_y) * SIZE_MMAP;
	draw_line (img,
		(int [2]){player.x * SIZE_MMAP, player.y * SIZE_MMAP},
		(int [2]){player.dirx_pxl, player.diry_pxl}, COLOR_PLAYER_MMP);
}
