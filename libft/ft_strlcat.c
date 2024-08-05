/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:35:07 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/16 10:51:30 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	k;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dest)
		len_src += size;
	else
		len_src += len_dest;
	k = 0;
	while (src[k] != '\0' && (len_dest + k) < size - 1)
	{
		dest[len_dest + k] = src[k];
		k++;
	}
	dest[len_dest + k] = '\0';
	return (len_src);
}

// int	main(void)
// {
// 	char		dest[13] = "Hello, ";
// 	const char	src[] = "world!";
// 	size_t		total_length = ft_strlcat(dest, src, sizeof(dest));

// 	printf("Concatenated string: %s\n", dest);
// 	printf("Total length: %zu\n", total_length);
// 	return (0);
// }
