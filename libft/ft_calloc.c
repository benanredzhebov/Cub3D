/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:11 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/14 13:04:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// int	main() 
// {
// 	int 	i;
// 	int		n;
// 	int		*a;

// 	printf ("Number of elements to be entered:");
// 	scanf ("%d", &n);

// 	a = ft_calloc(n, sizeof(int));
// 	printf ("Enter %d numbers:\n", n);
// 	for (i=0; i < n; i++ )
// 	{
// 		scanf("%d", &a[i]);
// 	}
// 	printf("The numbers entered are: ");
// 	for (i=0; i < n; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	free(a);
// 	return (0);
// }
