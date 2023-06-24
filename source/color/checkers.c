/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/24 11:50:51 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_ceiling(char *cardinal, t_game *game)
{
	if (!ft_strncmp("C", cardinal, 2) && game->texture.ceiling == -1)
		return (1);
	return (0);
}

int	is_floor(char *cardinal, t_game *game)
{
	if (!ft_strncmp("F", cardinal, 2) && game->texture.floor == -1)
		return (1);
	return (0);
}

int	is_color(char *line)
{
	if (ft_count_words(line, ',') != 3)
		return (0);
	return (1);
}
