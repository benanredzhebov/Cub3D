/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:24:04 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/15 10:27:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int main()
// {
//     char c;
//     char result;

//     c = '7';
//     result = ft_isdigit(c);
//     printf("The result is %d\n", result);

//     c = 'g';
//     result = ft_isdigit(c);
//     printf("The result is %d\n", result);

//     c = '+';
//     result = ft_isdigit(c);
//     printf("The result is %d\n", result);

//     return (0);
// }
