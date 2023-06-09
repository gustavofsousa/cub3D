/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/07 12:50:16 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_north(char *cardinal, t_game *game)
{
	if (!ft_strncmp("NO", cardinal, 3) && !game->texture.north.ptr)
		return (1);
	return (0);
}

int	is_south(char *cardinal, t_game *game)
{
	if (!ft_strncmp("SO", cardinal, 3) && !game->texture.south.ptr)
		return (1);
	return (0);
}

int	is_west(char *cardinal, t_game *game)
{
	if (!ft_strncmp("WE", cardinal, 3) && !game->texture.west.ptr)
		return (1);
	return (0);
}

int	is_east(char *cardinal, t_game *game)
{
	if (!ft_strncmp("EA", cardinal, 3) && !game->texture.east.ptr)
		return (1);
	return (0);
}
