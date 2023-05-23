/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:49:32 by gusousa           #+#    #+#             */
/*   Updated: 2023/05/23 10:23:43 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen_gnl(char *str, int *end_flag)
{
	int	len;

	len = 0;
	*end_flag = 1;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len + 1);
		len++;
	}
	*end_flag = 0;
	return (len);
}

char	*ft_calloc_gnl(size_t n_elements, size_t size)
{
	size_t	i;
	char	*str;

	if (!n_elements || !size)
	{
		n_elements = 1;
		size = 1;
	}
	str = malloc(n_elements * size);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < n_elements * size)
		str[i] = 0;
	return (str);
}

void	ft_strlcpy_gnl(char *dst, char *src, int size)
{
	int	i;
	int	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src])
		len_src++;
	while (src[i] && (i < size - 1) && i < len_src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strdup_gnl(char *src, int len_stash)
{
	char	*new;

	new = malloc(len_stash + 1);
	if (!new)
		return (0);
	ft_strlcpy_gnl(new, src, len_stash + 1);
	move_remains(src, len_stash);
	return (new);
}
