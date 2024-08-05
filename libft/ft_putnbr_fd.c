/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:52:25 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/22 16:09:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

// int main(void)
// {
// 	int num1 = 12345;
// 	int num2 = -9876;
// 	int num3 = 0;
// 	int num4 = -2147483648;

// 	printf("Testing ft_putnbr_fd:\n");

// 	printf("Number %d: ", num1);
// 	ft_putnbr_fd(num1, 1);
// 	printf("\n");

// 	printf("Number %d: ", num2);
// 	ft_putnbr_fd(num2, 1);
// 	printf("\n");

// 	printf("Number %d: ", num3);
// 	ft_putnbr_fd(num3, 1);
// 	printf("\n");

// 	printf("Number %d: ", num4);
// 	ft_putnbr_fd(num4, 1);
// 	printf("\n");

// 	return 0;
// }
