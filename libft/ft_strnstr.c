/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavosousa <gustavosousa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:02:13 by gusousa           #+#    #+#             */
/*   Updated: 2023/05/28 17:58:12 by gustavosous      ###   ########.fr       */
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
	return (NULL);
}
