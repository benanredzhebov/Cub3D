/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:08:34 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/26 10:11:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function allocates (using 'malloc()') and returns a substring from the
** string 's'.
** The substring begins at index 'start' and is as maximum size 'len'.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	total_len;
	size_t	counter;

	if (!s)
		return (NULL);
	if (!len || start >= (ft_strlen(s)))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	total_len = start + len;
	counter = 0;
	while (start < total_len)
	{
		substr[counter] = s[start];
		start++;
		counter++;
	}
	substr[counter] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	const char *original = "Hello world";
// 	unsigned int	start_position = 7;
// 	size_t	substring_length = 5;
// 	char *substring = ft_substr(original, start_position, substring_length);

// 	if(substring != NULL)
// 	{
// 		printf("Original: %s\n", original);
// 		printf("Substring is: %s\n:", substring);
// 		free(substring);
// 	}
// 	else
// 		printf("Substring extraction failed.\n");
// 	return (0);
// }

/*Function for substring extraction

char const *s: This parameter represents the input string 
from which you want to extract a substring. 
It's a pointer to a constant character, 
meaning the function won't modify the original string.

unsigned int start: This parameter indicates the starting 
index of the substring you want to extract from the input string s.

size_t len: This parameter specifies the length of the substring 
you want to extract.

*/