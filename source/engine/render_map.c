#include "../../include/cub3d.h"

void	render_map2d(t_data *data, int square_sz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COLUMN)
		{
			if (data->map[i][j] == 1)
				draw_square(&data->img, i * square_sz, j * square_sz,
					0xFF0000);
			else
				draw_square(&data->img, i * square_sz, j * square_sz,
					0xFFF000);
			j++;
		}
		i++;
	}
}

void	render_map3d(t_data *data)
{
	double	w;
	int		color_a;
	int		color_b;

	w = LENGHT;
	color_a = 0x777777;
	color_b = 0xCCCCCC;
	draw_background(*data, color_a, color_b);
	color_a = 0x529e35;
	color_b = 0x32aa6e;
	load_textures(data);
	render_walls(data, color_a, color_b);
}
