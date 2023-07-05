/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 15:09:09 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	bresenham_x(t_img *img, int i[2], int f[2], int color)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (ft_abs(f[1] - i[1]));
	b = a - 2 * (ft_abs(f[0] - i[0]));
	p = a - (f[0] - i[0]);
	pixel_put(img, i[0], i[1], color);
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
		pixel_put(img, i[0], i[1], color);
	}
}

void	bresenham_y(t_img *img, int i[2], int f[2], int color)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (ft_abs(f[0] - i[0]));
	b = a - 2 * (ft_abs(f[1] - i[1]));
	p = a - (f[1] - i[1]);
	pixel_put(img, i[0], i[1], color);
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
		pixel_put(img, i[0], i[1], color);
	}
}
