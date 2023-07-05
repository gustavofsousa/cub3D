/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 12:18:58 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix_int(t_game *game)
{
	int	i;

	if (game->map.mtx_int)
	{
		i = -1;
		while (++i < game->map.rows)
			free(game->map.mtx_int[i]);
		free(game->map.mtx_int);
	}
}

void	update_matrix(char ***matrix, char *new_line)
{
	char	**new_matrix;
	int		i;

	i = 0;
	if (!*matrix)
	{
		*matrix = malloc(sizeof(char *) * 2);
		(*matrix)[0] = ft_strdup(new_line);
		(*matrix)[1] = NULL;
	}
	else
	{
		while ((*matrix)[i])
			i++;
		new_matrix = malloc(sizeof(char *) * (i + 2));
		i = -1;
		while ((*matrix)[++i])
			new_matrix[i] = ft_strdup((*matrix)[i]);
		new_matrix[i] = ft_strdup(new_line);
		new_matrix[i + 1] = NULL;
		ft_free_matrix(*matrix);
		*matrix = new_matrix;
	}
}

void	print_mtx(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			printf("%d", game->map.mtx_int[i][j]);
		}
		printf("\n");
	}
}

int	**malloc_matrix_int(int height, int width)
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
