/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:14 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/14 13:52:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) || (ft_isdigit(c)))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	c;
// 	char	result;

// 	c = '*';
// 	result = ft_isalnum(c);
// 	printf("The character is not alphanumeric: %d\n", result);

// 	c = 'g';
// 	result = ft_isalnum(c);
// 	printf("The character is alphanumeric %d\n", result);

// 	c = '+';
// 	result = ft_isalnum(c);
// 	printf("The character is not alphanumeric: %d\n", result);

// 	c = '6';
// 	result = ft_isalnum(c);
// 	printf("The character is alphanumeric: %d\n", result);

// 	return (0);
// }
