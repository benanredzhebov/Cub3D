/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:37:30 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:37:31 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

/*
This function takes a pointer to a memory location"s",
a value to fill that memory location with"c", and 
then a number of bytes to fill "n" as parameters. It loops
through the memory location starting from the end and
filling each byte with the given value "c", until it
has filled the specified number of bytes "n". Finally, 
it returns the pointer to the memory location that was
modified.
*/