/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:30:27 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/22 14:58:38 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int main()
// {
//     char c;
//     char result;

//     c = '123';
//     result = ft_isprint(c);
//     printf("The result is %d\n", result);

//     c = 'g';
//     result = ft_isprint(c);
//     printf("The result is %d\n", result);

//     c = '+';
//     result = ft_isprint(c);
//     printf("The result is %d\n", result);

//     return (0);
// }

/*We can change if the character is printable with function
int iscntrl(int argument);*/ 