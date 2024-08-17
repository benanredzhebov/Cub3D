/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:39:27 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:28 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s2);
	if (!j)
		return ((char *) s1);
	if (!n)
		return (0);
	while (s1[i] && i + j <= n)
	{
		if (!ft_strncmp(&s1[i], s2, j))
			return ((char *) &s1[i]);
		i++;
	}
	return (0);
}

/*
strnstr searches for a substring in
a string up to a specified length.
it takes 3 parameters which are 
string to search in (s1)
substring to search for (s2),
maximum length (n).
size_t is used for the loop counters
and array indexing.
as size_t is an unsigned integral type used
to represent the size of objects in bytes.
The function returns a pointer to the beginning
of the substring if it is found
or NULL if it is not found.
*/