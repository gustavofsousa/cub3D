/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:44:02 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/26 09:45:24 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(source);
	if (!dest_size)
		return (src_len);
	i = 0;
	while (source[i]
		&& (i < dest_size - 1)
		&& (i < src_len))
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}
