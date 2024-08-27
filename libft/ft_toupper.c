/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:00:44 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/16 20:02:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return (c);
}

// int	main(void)
// {
// 	char	ch;

// 	ch = 'b';
// 	printf ("Before the function the text is %c\n", ch);
// 	ch = ft_toupper(ch);
// 	printf ("After the function the text is %c\n", ch);
// 	return (0);
// }
