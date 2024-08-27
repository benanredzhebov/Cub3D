/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:30:24 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/23 15:41:38 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = 0;
		i++;
	}
}

// int	main()
// {
// 	char buffer[5] = "Benan";

// 	printf("Text before ft_bzero: %s\n", buffer);

// 	ft_bzero(buffer, 5);
// 	printf("Text after ft_bzero: %s\n", buffer);
// 	return 0;
// }
