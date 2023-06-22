#include "../../../include/cub3d.h"

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

	size = 22;
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

void	render_player(t_img *img, t_player player, int l)
{
	int	plan_xn;
	int	plan_yn;
	int	plan_xp;
	int	plan_yp;

	plan_xn = (player.x + player.dirX - player.cam_plane_dirX) * 22;
	plan_yn = (player.y + player.dirY - player.cam_plane_dirY) * 22;
	plan_xp = (player.x + player.dirX + player.cam_plane_dirX) * 22;
	plan_yp = (player.y + player.dirY + player.cam_plane_dirY) * 22;
	draw_player_square(img, player, l);
	player.dirx_pxl = (player.x + player.dirX) * 22;
	player.diry_pxl = (player.y + player.dirY) * 22;
	draw_line (img, (int [2]){player.x * 22, player.y * 22},
		(int [2]){player.dirx_pxl, player.diry_pxl}, 0x0000FF);
	pixel_put(img, plan_xn, plan_yn, 0x0000FF);
	pixel_put(img, plan_xp, plan_yp, 0x0000FF);
}
