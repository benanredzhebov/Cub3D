/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:39:34 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:34 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (char) c)
			return ((char *)s + i);
	return (NULL);
}

/*
ft_strrchr locates the last occurrence
of a character in a string. The function
takes in two parameters, the string(const char *) s,
and  character (int c) to be found.
*/