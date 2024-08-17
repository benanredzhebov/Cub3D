/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:38:35 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:38:35 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	while (*s)
	{
		f(index, s);
		s++;
		index++;
	}
}

/*
ft_striteri iterates over each character of the string s
and applies the function f to each character. The
function f takes two args: the index of the char and a ptr
to the char itself. It can modify the character if necessary.
*/