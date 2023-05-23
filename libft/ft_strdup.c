/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:50:18 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/26 10:02:20 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*my_copy;
	size_t	len;

	len = ft_strlen(s1);
	my_copy = malloc(len + 1);
	if (!my_copy)
		return (NULL);
	ft_memcpy(my_copy, s1, len + 1);
	return (my_copy);
}
