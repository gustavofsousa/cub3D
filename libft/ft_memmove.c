/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:49:39 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/25 17:01:55 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t len)
{
	if (dest == 0 && source == 0 && len > 0)
		return (0);
	if (source < dest)
		while (len--)
			((char *)dest)[len] = ((char *)source)[len];
	else
		ft_memcpy(dest, source, len);
	return (dest);
}
