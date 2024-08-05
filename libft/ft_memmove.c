/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:40:40 by beredzhe          #+#    #+#             */
/*   Updated: 2023/12/01 14:13:41 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (!s && !d)
		return (NULL);
	i = 0;
	if (d >= s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// int	main()
// {
// 	char	dest[] = "Benan";
// 	const char	src[] = "Memo";

// 	printf("Before memmove dest = %s, src = %s\n", dest, src);
// 	printf("After memmove dest = %s\n", ft_memmove(dest, src, 3));
// 	return(0);
// }
