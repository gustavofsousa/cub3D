/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:02:16 by gusousa           #+#    #+#             */
/*   Updated: 2022/11/17 08:43:22 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char sep)
{
	size_t	i;
	size_t	qtd_word;
	size_t	next;

	i = 0;
	qtd_word = 0;
	while (s[i])
	{
		next = i + 1;
		if (s[i] != sep && (s[next] == sep || s[next] == '\0'))
			qtd_word++;
		i++;
	}
	return (qtd_word);
}

static char	**split(char	**str_splitted, char const *s, char sep)
{
	size_t	qtd_words;
	size_t	line;
	size_t	word_len;

	qtd_words = count_words(s, sep);
	line = 0;
	while (line < qtd_words)
	{
		word_len = 0;
		while (*s && (word_len == 0 || *s != sep))
		{
			if (*s != sep)
				word_len++;
			s++;
		}
		str_splitted[line] = ft_substr(s - word_len, 0, word_len);
		line++;
	}
	str_splitted[line] = 0;
	return (str_splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**str_splitted;
	size_t	qtd_words;

	if (!s)
		return (NULL);
	qtd_words = count_words(s, c);
	str_splitted = malloc((qtd_words + 1) * sizeof(char *));
	if (!str_splitted)
		return (NULL);
	return (split(str_splitted, s, c));
}
