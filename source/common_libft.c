/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusta <gusta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/03 10:38:40 by gusta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = -1;
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
}

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
		free_matrix(*matrix);
		*matrix = new_matrix;
	}
}

/*
** Split the string s using the char sep as separator.
** Count the number of words.
*/
int	ft_count_words(char const *s, char sep)
{
	char	**mtx;
	int		count;

	count = 0;
	mtx = ft_split(s, sep);
	while (mtx[count])
		count++;
	free_matrix(mtx);
	return (count);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
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

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
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