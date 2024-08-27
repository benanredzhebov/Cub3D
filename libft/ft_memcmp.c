/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:01:37 by beredzhe          #+#    #+#             */
/*   Updated: 2023/12/01 09:31:18 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	i = 0;
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// int	main()
// {
// 	char str1[] = "Hello";
// 	char str2[] = "World";

// 	int result = ft_memcmp(str1, str2, 2);

// 	if (result < 0) 
// 	{
// 		printf("str1 is less than str2\n");
// 	}
// 	else if (result > 0) 
// 	{
// 		printf("str1 is greater than str2\n");
// 	}
// 	else
// 	{
// 		printf("str1 is equal to str2\n");
// 	}

//     return 0;
// }
