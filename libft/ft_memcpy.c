/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:24:53 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/23 10:20:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	size_t	i;

	if (!to && !from)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)to)[i] = ((unsigned char *)from)[i];
		i++;
	}
	return (to);
}

// int main()
// {
// 	const char from[50] = "Benan";
// 	char to[50];
// 	strcpy(to,"Heloooo!!");
// 	printf("Before memcpy to = %s\n", to);
// 	ft_memcpy(to, from, 2);
// 	printf("After memcpy to = %s\n", to);

// 	return(0);
// }
