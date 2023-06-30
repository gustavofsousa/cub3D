/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:37:54 by fcaetano          #+#    #+#             */
/*   Updated: 2023/06/27 10:18:47 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65362 || keycode == 119)
		game->key.w_is_press = 1;
	if (keycode == 65364 || keycode == 115)
		game->key.s_is_press = 1;
	if (keycode == 65363)
		game->key.ra_is_press = 1;
	if (keycode == 65361)
		game->key.la_is_press = 1;
	if (keycode == 97)
		game->key.a_is_press = 1;
	if (keycode == 100)
		game->key.d_is_press = 1;
	if (keycode == 109)
		game->key.m_is_press = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 65362 || keycode == 119)
		game->key.w_is_press = 0;
	if (keycode == 65364 || keycode == 115)
		game->key.s_is_press = 0;
	if (keycode == 65363 || keycode == 100)
		game->key.ra_is_press = 0;
	if (keycode == 65361 || keycode == 97)
		game->key.la_is_press = 0;
	if (keycode == 109)
		game->key.m_is_press = 0;
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->key.w_is_press || game->key.s_is_press
		|| game->key.ra_is_press || game->key.la_is_press)
	{
		if (game->key.w_is_press)
			walk_forward (game);
		if (game->key.s_is_press)
			walk_backward (game);
		if (game->key.ra_is_press)
			turn_right (&game->player);
		if (game->key.la_is_press)
			turn_left (&game->player);
	}
	render_map3d(game);
	if (game->key.m_is_press)
	{
    	render_map2d(game, SIZE_MMAP);
    	render_player(&game->img, game->player, 9);
	}
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	//mlx_destroy_window (game->img.ptr, game->img.win);
	return (0);
}

int	**malloc_ma(int height, int width)
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

void transposeMatrix(t_game *game) 
{
	int **mtx = malloc_ma(game->map.rows, game->map.cols);
	int tmp;
	int i;
	int j;

	i = -1;
	tmp = game->map.rows;
    while (++i < game->map.rows) 
	{
		j = -1;
        while (++j < game->map.cols) 
		{
            mtx[j][i] = game->map.mtx_int[i][j];
        }
    }
	free_matrix_int(game);
	game->map.cols = game->map.rows;
	game->map.rows = tmp;
	game->map.mtx_int = mtx;

}

void	render_game(t_game *game)
{
	mlx_clear_window(game->img.ptr, game->img.win);
	transposeMatrix(game);
	render_map3d(game);
	mlx_hook(game->img.win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->img.win, 3, 1L << 1, handle_key_release, game);
	mlx_hook(game->img.win, 17, 0, close_window, game);
	mlx_loop_hook(game->img.ptr, loop_hook, game);
	mlx_put_image_to_window(game->img.ptr, game->img.win,
		game->img.img, 0, 0);
	mlx_loop(game->img.ptr);
}
