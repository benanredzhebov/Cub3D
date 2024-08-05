/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:53:03 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/22 16:56:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
	}
	while (nbr > 0)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		nb;

	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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

// int	main(void)
// {
// 	int num1 = 12345;
// 	int num2 = -6789;
// 	int num3 = 0;
// 	int num4 = -2147483648;

// 	char *str1 = ft_itoa(num1);
// 	char *str2 = ft_itoa(num2);
// 	char *str3 = ft_itoa(num3);
// 	char *str4 = ft_itoa(num4);

// 	printf("Number: %d, String: %s\n", num1, str1);
// 	printf("Number: %d, String: %s\n", num2, str2);
// 	printf("Number: %d, String: %s\n", num3, str3);
// 	printf("Number: %d, String: %s\n", num4, str4);

// 	free(str1);
// 	free(str2);
// 	free(str3);
// 	free(str4);

// 	return 0;
// }
