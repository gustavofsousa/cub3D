/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:50:55 by gusousa           #+#    #+#             */
/*   Updated: 2022/05/30 17:07:51 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int nbr, int signal)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	if (signal == -1)
		len++;
	return (len);
}

static char	*convert_itoa(char *the_string, unsigned int nbr, int len)
{
	*(the_string + len--) = '\0';
	if (nbr == 0)
		*(the_string + len) = '0';
	while (nbr)
	{
		*(the_string + len--) = nbr % 10 + '0';
		nbr /= 10;
	}
	return (the_string);
}

char	*ft_itoa(int nbr)
{
	unsigned int	nbr_unsig;
	size_t			nbr_len;
	char			*the_string;
	int				signal;

	signal = 0;
	if (nbr < 0)
	{
		nbr_unsig = (unsigned int)nbr * -1;
		signal = -1;
	}
	else
		nbr_unsig = (unsigned int)nbr;
	nbr_len = ft_nbrlen(nbr_unsig, signal);
	the_string = ft_calloc(nbr_len + 1, sizeof(char));
	if (!the_string)
		return (NULL);
	if (signal < 0)
		*the_string = '-';
	return (convert_itoa(the_string, nbr_unsig, nbr_len));
}
