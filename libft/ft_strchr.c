/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:56:49 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/23 14:59:32 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

// int	main()
// {
// 	const char str[] = "Benan Redzhebov";
// 	const char ch = 'R';
// 	char *ret;

// 	ret = ft_strchr(str, ch);

// 	if (ret == NULL)
// 		printf("Character '%c' not found in the string.\n", ch);
//     else
// 		printf("String after '%c' is: %s\n", ch, ret + 1);
// 	return (0);
// }
