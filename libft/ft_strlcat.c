/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:50:51 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/25 14:03:32 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t dest_max)
{
	size_t	dest_len;
	size_t	i;

	dest_len = 0;
	while (dest[dest_len] && dest_len < dest_max)
		dest_len++;
	i = 0;
	while (source[i] && (dest_len + i + 1) < dest_max)
	{
		dest[dest_len + i] = source[i];
		i++;
	}
	if (dest_len < dest_max)
		dest[dest_len + i] = '\0';
	return (dest_len + ft_strlen(source));
}
