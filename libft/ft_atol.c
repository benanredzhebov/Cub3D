/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:29:53 by oruban            #+#    #+#             */
/*   Updated: 2024/01/24 19:32:40 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Does the same as ft_atoi() but for long integer */

#include "libft.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i])
	{
		while ('\t' == str[i] || '\n' == str[i] || '\v' == str[i]
			|| '\f' == str[i] || '\r' == str[i] || ' ' == str[i])
			i++;
		if ('+' == str[i] || '-' == str[i])
		{
			if ('-' == str[i])
				sign = -sign;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = 10 * num + str[i] - '0';
			i++;
		}
	}
	return (sign * num);
}
