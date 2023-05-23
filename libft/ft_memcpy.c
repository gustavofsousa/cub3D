/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:03:27 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/25 17:02:34 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t	i;

	if (dest == 0 && source == 0 && n > 0)
		return (0);
	i = 0;
	while (n--)
	{
		((char *)dest)[i] = ((char *)source)[i];
		i++;
	}
	return (dest);
}
