/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:36:18 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/16 20:05:23 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	to_find;

	i = 0;
	s = (unsigned char *)str;
	to_find = (unsigned char)c;
	while (i < n)
	{
		if (s[i] == to_find)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

// int	main(void) 
// {
// 	const char	str[] = "http://www.tutorialspoint.com";
// 	const char	ch = ':';
// 	char	*ret;

// 	ret = memchr(str, ch, ft_strlen(str));

// 	printf("String after |%c| is - |%s|\n", ch, ret);

// 	return(0);
// }
