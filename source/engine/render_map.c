#include "../../include/cub3d.h"

void	render_map2d(t_game *game, int square_sz)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.mtx[i][j] == 1)
				draw_square(&game->img, i * square_sz, j * square_sz,
					0xFF0000);
			else
				draw_square(&game->img, i * square_sz, j * square_sz,
					0xFFF000);
			j++;
		}
		i++;
	}
}

void	render_map3d(t_game *game)
{
	double	w;
	int		color_a;
	int		color_b;

	w = LENGHT;
	color_a = 0x777777;
	color_b = 0xCCCCCC;
	draw_background(*game, color_a, color_b);
	color_a = 0x529e35;
	color_b = 0x32aa6e;
	load_textures(game);
	raycast(game, color_a, color_b);
}
