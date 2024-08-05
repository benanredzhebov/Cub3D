/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:13:26 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/15 10:22:22 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int main()
// {
//     char c;
//     char result;

//     c = '7';
//     result = ft_isascii(c);
//     printf("The result is %d\n", result);

//     c = 'g';
//     result = ft_isascii(c);
//     printf("The result is %d\n", result);

//     c = 128;
//     result = ft_isascii(c);
//     printf("The result is %d\n", result);

//     return (0);
// }
