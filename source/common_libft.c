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
void    update_matrix(char ***matrix, char *new_line)
{
    char    **new_matrix;
    int     i;

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

static size_t	ft_count_words(char const *s, char sep)
{
	size_t	i;
	size_t	qtd_word;
	size_t	next;

	i = 0;
	qtd_word = 0;
	while (s[i])
	{
		next = i + 1;
		if (s[i] != sep && (s[next] == sep || s[next] == '\0'))
			qtd_word++;
		i++;
	}
	return (qtd_word);
}