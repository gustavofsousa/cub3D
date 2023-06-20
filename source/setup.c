/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/19 15:24:04 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (game->mlx.ptr == NULL)
		return (-1);
	return (0);
}

void	init_variables(t_game *game)
{
// mlx
	game->mlx.height = 600;
	game->mlx.width = 600;
// Map
	game->map.height = 0;
	game->map.width = 0;
	game->map.mtx = NULL;
	game->map.mtx_int = NULL;
// texture
	game->texture.north.ptr = NULL;
	game->texture.south.ptr = NULL;
	game->texture.west.ptr = NULL;
	game->texture.east.ptr = NULL;
	game->texture.ceiling = -1;
	game->texture.floor = -1;
}

void	setup(t_game *game)
{
	init_variables(game);
	init_mlx(game);
}
