/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/24 11:48:20 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	create_window_mlx(t_game *game)
{
	game->img.win = mlx_new_window(game->img.ptr, LENGHT, HEIGHT, "cub3D");
	if (game->img.win == NULL)
		exit_game("error: mlx window failed", game);
	game->img.img = mlx_new_image(game->img.ptr, LENGHT, HEIGHT);
	if (game->img.img == NULL)
		exit_game("error: mlx image failed", game);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	if (game->img.addr == NULL)
		exit_game("error: mlx address failed", game);
}

void	init_mlx(t_game *game)
{
	game->img.ptr = mlx_init();
	if (game->img.ptr == NULL)
		exit_game("error: mlx init failed", game);
}

void	init_var_raycasting(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.cam_plane_dir_x = 0;
	game->player.cam_plane_dir_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.speed = 0.05;
	game->player.rot_speed = 0.019;
	game->key.w_is_press = 0;
	game->key.a_is_press = 0;
	game->key.s_is_press = 0;
	game->key.d_is_press = 0;
	game->key.la_is_press = 0;
	game->key.ra_is_press = 0;
	game->key.m_is_press = 0;
}

void	init_var_map(t_game *game)
{
	game->img.height = 0;
	game->img.width = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.mtx = NULL;
	game->map.mtx_int = NULL;
	game->texture.north.ptr = NULL;
	game->texture.south.ptr = NULL;
	game->texture.west.ptr = NULL;
	game->texture.east.ptr = NULL;
	game->texture.ceiling = -1;
	game->texture.floor = -1;
}

void	setup(t_game *game)
{
	init_var_map(game);
	init_var_raycasting(game);
	init_mlx(game);
}
