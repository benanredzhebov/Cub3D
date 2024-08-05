/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:26:48 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/14 11:30:37 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	return (result);
}

// int main()
// {
//     int val;
//     char strn1[] = "12546";

//     val = ft_atoi(strn1);
//     printf("String value = %s\n", strn1);
//     printf("Integer value = %d\n", val);

//     char strn2[] = "GeeksforGeeks";
//     val = ft_atoi(strn2);
//     printf("String value = %s\n", strn2);
//     printf("Integer value = %d\n", val);

// 	char strn3[] = "-345 8765\n5";
//     val = ft_atoi(strn2);
//     printf("String value = %s\n", strn3);
//     printf("Integer value = %d\n", val);

//     return (0);
// }

/*This function converts a string representation of an 
integer to an actual integer value.*/