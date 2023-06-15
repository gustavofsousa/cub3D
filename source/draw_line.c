/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:01:55 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 16:57:36 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	bresenham_x(t_img *img, int i[2], int f[2])
{
	int	a;
	int	b;
	int	p;

	a = 2 * (abs(f[1] - i[1]));
	b = a - 2 * (abs(f[0] - i[0]));
	p = a - (f[0] - i[0]);
	pixel_put(img, i[0], i[1], 0xFFF000);
	while (i[0] != f[0] || i[1] != f[1])
	{
		if (p < 0)
			p += a;
		else
		{
			if (i[1] > f[1])
				i[1]--;
			else
				i[1]++;
			p += b;
		}
		i[0]++;
		pixel_put(img, i[0], i[1], 0xFFF000);
	}
}

static void	bresenham_y(t_img *img, int i[2], int f[2])
{
	int	a;
	int	b;
	int	p;

	a = 2 * (abs(f[0] - i[0]));
	b = a - 2 * (abs(f[1] - i[1]));
	p = a - (f[1] - i[1]);
	pixel_put(img, i[0], i[1], 0xFFF000);
	while (i[0] != f[0] || i[1] != f[1])
	{
		if (p < 0)
			p += a;
		else
		{
			if (i[0] > f[0])
				i[0]--;
			else
				i[0]++;
			p += b;
		}
		i[1]++;
		pixel_put(img, i[0], i[1], 0xFFF000);
	}
}

void	draw_line(t_img *img, int i[2], int f[2])
{
	int	dist_x;
	int	dist_y;

	dist_x = abs(f[0] - i[0]); //CONFIRM THAT ABS CAN BE USED
	dist_y = abs(f[1] - i[1]);
	if (dist_x >= dist_y)
	{
		if (i[0] < f[0])
			bresenham_x(img, i, f);
		else
			bresenham_x(img, f, i);
	}
	else
	{
		if (i[1] < f[1])
			bresenham_y(img, i, f);
		else
			bresenham_y(img, f, i);
	}
}
