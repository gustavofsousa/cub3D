/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/07 12:42:33 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_cell(char map_cell)
{
	if (ft_strchr("NSEW 01", map_cell) != 0)
		return (1);
	return (0);
}

void	validate_char(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.mtx[++i])
	{
		j = -1;
		while (game->map.mtx[i][++j])
		{
			if (!is_valid_cell(game->map.mtx[i][j]))
				exit_game("Error: not permitted char in map", game);
		}
	}
}
