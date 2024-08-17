/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:32:46 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:32:48 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

void		ft_put_hex(unsigned int number, const char format);
void		ft_put_ptr(uintptr_t nb);
int			ft_len(int number);
int			hex_len(unsigned int number);
int			len_ptr(uintptr_t nb);
int			ft_unsigned_len(unsigned int nb);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_puthex(unsigned int number, const char format);
int			ft_putptr(uintptr_t ptr);
int			ft_putunsigned(unsigned int nb);
int			ft_conversion(va_list val, const char format);
int			ft_printf(const char *format, ...);
char		*ft_char(char *str, unsigned int number, int len);
char		*ft_itoa(int input);
char		*ft_uitoa(unsigned int nb);

#endif
