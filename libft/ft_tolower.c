/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:57:27 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/16 20:00:36 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

// int	main(void)
// {
// 	char	ch;

// 	ch = 'B';
// 	printf("Before the function the text is %c\n", ch);
// 	ch = ft_tolower(ch);
// 	printf ("After the function the text is %c\n", ch);
// 	return (0);
// }
