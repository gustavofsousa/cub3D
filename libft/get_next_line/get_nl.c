/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:09:48 by gusousa           #+#    #+#             */
/*   Updated: 2023/05/23 10:23:32 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	move_remains(char *str, int pos)
{
	int	j;

	j = 0;
	while (str[pos])
		str[j++] = str[pos++];
	str[j] = '\0';
}

char	*ft_append(char *line, char *s2, int len_stash)
{
	char	*new;
	int		line_len;

	line_len = 0;
	while (line[line_len])
		line_len++;
	new = malloc(line_len + len_stash + 1);
	if (!new)
		return (0);
	ft_strlcpy_gnl(new, line, line_len + 1);
	ft_strlcpy_gnl(&new[line_len], s2, len_stash + 1);
	move_remains(s2, len_stash);
	free(line);
	return (new);
}

char	*divide_et_vince(int fd, char *line, char *stash)
{
	int	nbyte;
	int	end_flag;
	int	len_stash;

	end_flag = 0;
	if (stash[0] != '\0')
	{
		len_stash = ft_strlen_gnl(stash, &end_flag);
		line = ft_strdup_gnl(stash, len_stash);
	}
	while (end_flag == 0)
	{
		nbyte = read(fd, stash, BUFFER_SIZE);
		if (nbyte <= 0 && *stash == 0)
			break ;
		stash[nbyte] = '\0';
		len_stash = ft_strlen_gnl(stash, &end_flag);
		if (line == 0)
			line = ft_strdup_gnl(stash, len_stash);
		else
			line = ft_append(line, stash, len_stash);
	}
	return (line);
}

char	*get_nl(int fd)
{
	static char	stash[4096][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = 0;
	line = divide_et_vince(fd, line, stash[fd]);
	return (line);
}
