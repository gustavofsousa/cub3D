/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 12:08:52 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_ruchoa(char *str1, int nbr)
{
	char	*color_str;

	color_str = ft_itoa(nbr);
	if (ft_strncmp(str1, color_str, ft_strlen(str1)))
	{
		free(color_str);
		return (0);
	}
	free(color_str);
	return (1);
}

int	is_valid_number(char **mtx, int r, int g, int b)
{
	if (mtx[0][0] == '-'
		|| mtx[1][0] == '-'
		|| mtx [2][0] == '-')
		return (0);
	if (!check_ruchoa(mtx[0], r)
		|| !check_ruchoa(mtx[1], g)
		|| !check_ruchoa(mtx[2], b))
		return (0);
	return (1);
}

void	invalid_rgb(char **mtx, t_game *game)
{
	ft_free_matrix(mtx);
	exit_game("Number rgb not valid", game);
}

int	translate_rgb(char *rgb, t_game *game)
{
	int		r;
	int		g;
	int		b;
	int		c;
	char	**lonely;

	if (ft_count_words(rgb, ',') != 3)
		exit_game("Number rgb not valid", game);
	lonely = ft_split(rgb, ',');
	r = ft_atoi(lonely[0]);
	g = ft_atoi(lonely[1]);
	b = ft_atoi(lonely[2]);
	if (!is_valid_number(lonely, r, g, b))
		invalid_rgb(lonely, game);
	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	ft_free_matrix(lonely);
	return (c);
}

void	get_color(t_game *game, char *line)
{
	char	*cardinal;
	char	**line_mtx;
	char	*arg;

	line_mtx = ft_split(line, ' ');
	cardinal = line_mtx[0];
	arg = line_mtx[1];
	if (is_ceiling(cardinal, game))
		game->texture.ceiling = translate_rgb(arg, game);
	else if (is_floor(cardinal, game))
		game->texture.floor = translate_rgb(arg, game);
	ft_free_matrix(line_mtx);
}
