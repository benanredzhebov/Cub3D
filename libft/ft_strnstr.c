/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:15:04 by beredzhe          #+#    #+#             */
/*   Updated: 2023/12/01 10:31:52 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] && i + j < len
				&& haystack[i + j] == needle[j])
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char	*haystack = "Hello, world!";
// 	const char	*needle = "w";
// 	size_t	len = 13;

// 	char *result = ft_strnstr(haystack, needle, len);

// 	if (result != NULL) 
// 		printf("Needle found at index: %ld\n", result - haystack);
//     else 
// 		printf("Needle not found.\n");
// 	return (0);
// }
