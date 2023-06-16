#include "../../include/cub3d.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	bresenham_x(t_img *img, int i[2], int f[2], int color)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (abs(f[1] - i[1]));
	b = a - 2 * (abs(f[0] - i[0]));
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

static void	bresenham_y(t_img *img, int i[2], int f[2], int color)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (abs(f[0] - i[0]));
	b = a - 2 * (abs(f[1] - i[1]));
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

void	draw_line(t_img *img, int i[2], int f[2], int color)
{
	int	dist_x;
	int	dist_y;

	dist_x = abs(f[0] - i[0]); //CONFIRM THAT ABS CAN BE USED
	dist_y = abs(f[1] - i[1]);
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

void draw_vertical_line(t_img *img, int x, int y0, int yf, int color)
{
	while (y0 <= yf)
	{
		pixel_put(img, x, y0, color);
		y0++;
	}
}

void	draw_square(t_img *img, int x0, int y0, int color, int l)
{
	int	x;
	int	y;

	x = x0;
	while (x < x0 + l)
	{
		y = y0;
		while (y < y0 + l)
		{
			pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}