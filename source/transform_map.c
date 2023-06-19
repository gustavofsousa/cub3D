/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/19 15:10:22 by gustavosous      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    transform_map_int(t_game *game)
{
    int i;
    int j;
    
    i = -1;
    game->map.mtx_int = malloc(sizeof(int *) * game->map.height);
    while (++i < game->map.height)
    {
        j = -1;
        game->map.mtx_int[i] = malloc(sizeof(int) * game->map.width);
        while (++j < game->map.width)
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
    }
}
