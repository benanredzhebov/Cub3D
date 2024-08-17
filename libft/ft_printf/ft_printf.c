/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:54:25 by demrodri          #+#    #+#             */
/*   Updated: 2023/12/18 22:45:13 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}

int	ft_conversion(va_list val, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(val, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(val, char *));
	else if (format == 'p')
		char_printed += ft_putptr(va_arg(val, uintptr_t));
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(val, int));
	else if (format == 'u')
		char_printed += ft_putunsigned(va_arg(val, unsigned int));
	else if (format == 'x' || format == 'X')
		char_printed += ft_puthex(va_arg(val, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	va_list	val;
	int		char_printed;

	index = 0;
	char_printed = 0;
	va_start(val, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			char_printed += ft_conversion(val, format[index + 1]);
			index++;
		}
		else
			char_printed += ft_putchar(format[index]);
		index++;
	}
	va_end(val);
	return (char_printed);
}

// int main()
// {
//     int min_num = -2147483648;
// 	int max_num = 2147483647;
// 	int hexa_num = 1390;
// 	int i = 2147483647;
// 	int num = 1;
//     char ch = 'A';
//     char *str = "hello, world!";
//     unsigned int u_num = 4294967295;
//     void *ptr = &num;
// 	ft_printf("Testing ft_printf:\n");
// 	ft_printf("Character: %c\n", ch);
//     ft_printf("String: %s\n", str);					
// 	ft_printf("Pointer: %p\n", ptr);
//     ft_printf("Max num: %d\n", max_num);
// 	ft_printf("Min num: %d\n", min_num);
// 	ft_printf("i: %i\n", i);
//     ft_printf("Unsigned Number: %u\n", u_num);
// 	ft_printf("hexa: %x\n", hexa_num);
// 	ft_printf("hexa: %X\n", hexa_num);
// 	ft_printf("Percent: %%\n", ptr);
// 	ft_printf("%p %p\n ", 0, 0);	
//     return (0);
// }
