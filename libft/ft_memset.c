/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:06:57 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/15 19:56:23 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

// int main()
// {
// 	char str[] = "Libc is the standard library.";
// 	printf("Before memset: %s\n", str);
// 	ft_memset(str, 'B', 2 *sizeof(char));
// 	printf("After memset: %s\n", str);

// 	return (0);
// }
