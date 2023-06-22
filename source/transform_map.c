/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/22 16:56:16 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_value(t_game *game, int i, int j)
{
	if (game->map.mtx[i][j] == '1' || game->map.mtx[i][j] == ' ')
		game->map.mtx_int[i][j] = 1;
	else if (game->map.mtx[i][j] == '0')
		game->map.mtx_int[i][j] = 0;
	else if (game->map.mtx[i][j] == 'N')
		game->map.mtx_int[i][j] = 2;
	else if (game->map.mtx[i][j] == 'S')
		game->map.mtx_int[i][j] = 3;
	else if (game->map.mtx[i][j] == 'E')
		game->map.mtx_int[i][j] = 4;
	else if (game->map.mtx[i][j] == 'W')
		game->map.mtx_int[i][j] = 5;
}

int	**malloc_matrix(int height, int width)
{
	int	**mtx;
	int	i;

	i = -1;
	mtx = malloc(sizeof(int *) * height);
	if (!mtx)
		return (NULL);
	while (++i < height)
	{
		mtx[i] = malloc(sizeof(int) * width);
		if (!mtx[i])
			return (NULL);
	}
	return (mtx);
}

void	transform_map_int(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->map.mtx_int = malloc_matrix(game->map.rows, game->map.cols);
	if (!game->map.mtx_int)
		return ;
	while (++i < game->map.cols)
	{
		j = -1;
		while (++j < game->map.cols)
			put_value(game, i, j);
	}
}
