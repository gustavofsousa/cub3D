/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/06/07 12:35:50 by gustavosous      ###   ########.fr       */
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

/* Receive a matrix
** Receive a line( non allocaded).
** If matrix is NULL, create a matrix the new_line.
** If matrix already exist, realloc it + 1 size and add the new_line.
*/
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
