/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:45:45 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/30 10:31:49 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elements, size_t element_size)
{
	void	*ret;

	if (!n_elements || !element_size)
	{
		n_elements = 1;
		element_size = 1;
	}
	ret = malloc(n_elements * element_size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, n_elements * element_size);
	return (ret);
}
