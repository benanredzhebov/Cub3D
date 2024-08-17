/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:38:16 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:38:16 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_toklen(const char *s, char c)
{
	size_t	tok_num;

	tok_num = 0;
	while (*s)
	{
		if (*s != c)
		{
			++tok_num;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (tok_num);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	split = malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			split[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	split[i] = NULL;
	return ((char **)split);
}

/*
ft_split splits a string into an array of substrings
based on a delimiter.
ft_toklen is used to determine the num of tokens
in a string by counting the non-delimiter char
and skipping over the delimiters.
*/