/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:39:39 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:40 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start_index;
	int		end_index;

	start_index = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start_index] && ft_set_char(s1[start_index], set))
		start_index++;
	end_index = ft_strlen(s1) - 1;
	while (end_index > start_index && ft_set_char(s1[end_index], set))
		end_index--;
	ptr = (char *)malloc(sizeof(char) * (end_index - start_index + 2));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1 + start_index, end_index - start_index + 1);
	ptr[end_index - start_index + 1] = '\0';
	return (ptr);
}

/*
ft_char_set checks whether a given char c exists in a
set of characters specified by the set string.
ft_strtrim is to remove any characters from the
beginning and end of s1 that are present in the
set string. It does so by finding the indices of
the first and last characters in s1 that are not
in the set. The function then allocates memory
for a new string, copies the trimmed substring
from s1 to the new string, and adds a null
terminator to the end.
*/