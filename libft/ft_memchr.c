/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:33:22 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:40:23 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	char	*s_char;

	s_char = (char *)s;
	while (n--)
	{
		if (*s_char == (char)c)
			return (s_char);
		s_char++;
	}
	return (0);
}
