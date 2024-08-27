/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:05:50 by beredzhe          #+#    #+#             */
/*   Updated: 2023/12/01 09:04:14 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'A' || c > 'Z') && \
	(c < 'a' || c > 'z'))
		return (0);
	return (1);
}

// int	main(void)
// {
// 	char c;

// 	c = 'Q';
// 	printf("\nUppercase alphabet is passed: %d", ft_isalpha(c));

// 	c = 'q';
// 	printf("\nLowercase alphabet is passed: %d", ft_isalpha(c));

// 	c = '+';
// 	printf("\nNon-alphabetic character is passed: %d\n", ft_isalpha(c));

// 	return (0);
// }

/*In C programming, isalpha() function checks whether a character is an alphabet
 (a to z and A-Z) or not.

If a character passed to isalpha() is an alphabet, it returns a non-zero integer,
 if not it returns 0.

The isalpha() function is defined in <ctype.h> header file.*/