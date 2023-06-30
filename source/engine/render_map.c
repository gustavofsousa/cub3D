/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:48:40 by fcaetano          #+#    #+#             */
/*   Updated: 2023/06/29 16:56:58 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_map2d(t_game *game, int square_sz)
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
				draw_square(&game->img, i * square_sz, j * square_sz,
					0xFF0000);
			else
				draw_square(&game->img, i * square_sz, j * square_sz,
					0xFFF000);
		}
	}
}

void	render_map3d(t_game *game)
{
	draw_background(*game);
	raycast(game);
}
