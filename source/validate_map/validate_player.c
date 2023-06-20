/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/07 12:46:01 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_player(char map_cell)
{
	if (ft_strchr("NSEW", map_cell) != 0)
		return (1);
	return (0);
}

void	validate_player(t_game *game)
{
	int	i;
	int	j;
	int	qtd_player;

	qtd_player = 0;
	i = -1;
	while (game->map.mtx[++i])
	{
		j = -1;
		while (game->map.mtx[i][++j])
		{
			if (is_valid_player(game->map.mtx[i][j]))
			{
				game->player.x = j;
				game->player.y = i;
				qtd_player++;
			}
		}
	}
	if (qtd_player != 1)
		exit_game("Incorrect number of player", game);
}
