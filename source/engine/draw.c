/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:39:23 by fcaetano          #+#    #+#             */
/*   Updated: 2023/06/27 09:39:24 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

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

void	draw_square(t_img *img, int x0, int y0, int color)
{
	int	x;
	int	y;
	int	size;

	size = SIZE_MMAP;
	x = x0;
	while (x < x0 + size)
	{
		y = y0;
		while (y < y0 + size)
		{
			pixel_put(img, x, y, color);
			y++;
		}
		x++;
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
			pixel_put(img, x, y, 0x0FF000);
			y++;
		}
		x++;
	}
}

void	render_player(t_img *img, t_player player, int l)
{
	int	plan_xn;
	int	plan_yn;
	int	plan_xp;
	int	plan_yp;

	plan_xn = (player.x + player.dir_x - player.cam_plane_dir_x) * SIZE_MMAP;
	plan_yn = (player.y + player.dir_y - player.cam_plane_dir_y) * SIZE_MMAP;
	plan_xp = (player.x + player.dir_x + player.cam_plane_dir_x) * SIZE_MMAP;
	plan_yp = (player.y + player.dir_y + player.cam_plane_dir_y) * SIZE_MMAP;
	draw_player_square(img, player, l);
	player.dirx_pxl = (player.x + player.dir_x) * SIZE_MMAP;
	player.diry_pxl = (player.y + player.dir_y) * SIZE_MMAP;
	draw_line (img, (int [2]){player.x * SIZE_MMAP, player.y * SIZE_MMAP},
		(int [2]){player.dirx_pxl, player.diry_pxl}, 0x0000FF);
	pixel_put(img, plan_xn, plan_yn, 0x0000FF);
	pixel_put(img, plan_xp, plan_yp, 0x0000FF);
}
