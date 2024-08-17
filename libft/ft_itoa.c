/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:35:52 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:35:53 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_maxneg(char *dest, char *src)
{
	int	i;

	dest = malloc(12 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < 11)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		nb;

	str = NULL;
	if (n == -2147483648)
		return (ft_maxneg(str, "-2147483648"));
	nb = n;
	digit = ft_count(nb);
	if (n < 0)
		nb *= -1;
	str = malloc((digit + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	str[digit] = '\0';
	while (digit > 0)
	{
		str[digit - 1] = (nb % 10) + 48;
		nb /= 10;
		digit--;
	}
	if (n < 0)
		str[digit] = '-';
	return (str);
}
/*
ft_count counts the num of digits in a given int
by diving it by 10 until it becomes 0, incrementing
a counter along the way.
ft_isneg is  copying a specific string ("-2147483648")
into an allocated string dest. It handles the memory
allocation and null-termination of the resulting string.
ft_itoa is used to convert an integer into a string.
It takes an int `n` as input and returns a dynamically
allocated character array (`char *`) that represents
the integer as a string.
it handles both + and - num.
*/