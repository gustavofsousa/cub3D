/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:58:53 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/07/05 12:20:35 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char sep)
{
	char	**mtx;
	int		count;

	count = 0;
	mtx = ft_split(s, sep);
	while (mtx[count])
		count++;
	ft_free_matrix(mtx);
	return (count);
}
