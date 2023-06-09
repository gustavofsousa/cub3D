/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/22 15:52:49 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_up_down(char *line_updown, int pos)
{
	if (line_updown[pos] != '1' && line_updown[pos] != ' ')
		return (0);
	return (1);
}

int	validate_down(t_game *game)
{
	int		i;
	char	*line;
	int		last;
	int		pre_last;

	last = game->map.rows - 1;
	pre_last = game->map.rows - 2;
	line = game->map.mtx[last];
	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		if (line[i] == ' ' && !is_valid_up_down(game->map.mtx[pre_last], i))
			return (0);
	}
	return (1);
}

int	validate_up(t_game *game)
{
	int		i;
	char	*line;

	line = game->map.mtx[0];
	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		if (line[i] == ' ' && !is_valid_up_down(game->map.mtx[1], i))
			return (0);
	}
	return (1);
}
