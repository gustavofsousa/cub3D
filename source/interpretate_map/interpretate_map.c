/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:45:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/07/05 12:02:42 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_max_col(t_game *game, char *line)
{
	int	len_line;

	len_line = ft_strlen(line);
	if (len_line > game->map.cols)
		game->map.cols = len_line;
}

/*
** Cut the new line at the end of the line
** Decide if the line is a texture or a color or a map.
** Call the right function to interpretate the line.
*/
void	interpretate_line(t_game *game, char *line_pre)
{
	char	*line2;
	char	*line;

	line2 = ft_strtrim(line_pre, "\n");
	line = ft_strtrim(line2, " ");
	if (is_xpm(line))
		get_texture(game, line);
	else if (is_color(line))
		get_color(game, line);
	else
	{
		update_matrix(&game->map.mtx, line);
		game->map.rows++;
		get_max_col(game, line);
	}
	free(line);
}

/*
** Open the file to read.
** Read the file line by line.
** If the line is not empty, interpretate it.
** At end, check if all information needed was given.
*/
void	interpretate_map(t_game *game, char *file_path)
{
	char	*line;
	int		fd;

	fd = open_file(file_path);
	line = get_nl(fd);
	while (line)
	{
		if (!ft_is_empty_line(line))
			interpretate_line(game, line);
		else if (game->map.mtx)
		{
			free(line);
			close(fd);
			exit_game("Empty line or false information", game);
		}
		free(line);
		line = get_nl(fd);
	}
	if (!has_all_information(game))
	{
		close (fd);
		exit_game("Missing information", game);
	}
	close(fd);
}
