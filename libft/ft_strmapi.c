/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:56:49 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/27 10:26:03 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*result;

	if (!s)
		return (NULL);
	str = str_new(ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}

// char	uppercase(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (toupper(c));
// 	else
// 		return (tolower(c));
// }

// int main()
// {
// 	const char *input = "Hello, World!";
// 	char	*result = ft_strmapi(input, uppercase);

// 	printf("Original string: %s\n", input);
// 	printf("Modified string: %s\n", result);

// 	free(result);
// 	return 0;
// }
