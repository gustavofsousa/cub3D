/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/24 11:52:29 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_img	get_argure(char *path, t_game *game)
{
	t_img	texture;

	texture.ptr = mlx_init();
	texture.img = mlx_xpm_file_to_image(texture.ptr,
			path,
			&texture.width,
			&texture.height);
	if (!texture.img)
		exit_game("Invalid texture path", game);
	texture.addr = mlx_get_data_addr(texture.img,
			&texture.bpp,
			&texture.line_len,
			&texture.endian);
	return (texture);
}

int	get_texture(t_game *game, char *line)
{
	char	*cardinal;
	char	**line_mtx;
	char	*arg;

	if (ft_count_words(line, ' ') != 2)
		exit_game("Incorrect number of information", game);
	line_mtx = ft_split(line, ' ');
	cardinal = line_mtx[0];
	arg = line_mtx[1];
	if (is_north(cardinal, game))
		game->texture.north = get_argure(arg, game);
	else if (is_south(cardinal, game))
		game->texture.south = get_argure(arg, game);
	else if (is_west(cardinal, game))
		game->texture.west = get_argure(arg, game);
	else if (is_east(cardinal, game))
		game->texture.east = get_argure(arg, game);
	else
	{
		free_matrix(line_mtx);
		return (0);
	}
	free_matrix(line_mtx);
	return (1);
}

int	is_xpm(char *line)
{
	while (*line && *line != '.')
		line++;
	if (!ft_strncmp(line, ".xpm", 4) && *(line + 4) == '\0')
		return (1);
	return (0);
}
