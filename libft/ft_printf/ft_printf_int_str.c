/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:32:05 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:32:08 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(char *str, unsigned int number, int len)
{
	int	digit;

	while (number > 0)
	{
		digit = number % 10;
		str[len] = '0' + digit;
		number = number / 10;
		len--;
	}
	return (str);
}

int	ft_len(int number)
{
	int	len;

	len = 0;
	if (number <= 0)
		len = 1;
	while (number != 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

char	*ft_itoa(int input)
{
	char				*str;
	int					sign;
	int					len;
	unsigned int		number;

	sign = 1;
	len = ft_len(input);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (input == 0)
		str[0] = '0';
	if (input < 0)
	{
		sign *= -1;
		number = input * -1;
		str[0] = '-';
	}
	else
		number = input;
	str = ft_char(str, number, len);
	return (str);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free (num);
	return (len);
}
