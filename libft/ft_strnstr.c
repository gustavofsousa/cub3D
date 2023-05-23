/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:02:13 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/30 15:39:47 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	need_len;

	if (!(*needle))
		return ((char *)haystack);
	need_len = ft_strlen(needle);
	while (*haystack && n-- >= need_len)
	{
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, need_len))
				return ((char *)haystack);
		haystack++;
	}
	return (0);
}
