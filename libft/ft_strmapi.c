/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:39:08 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:09 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*result;

	len = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (result == NULL)
		return (result);
	while (s[len] != '\0')
	{
		result[len] = f(len, s[len]);
		len++;
	}
	result[len] = '\0';
	return (result);
}

/*
ft_strmapi applies the function f to each character of a string s
and create a new string. f takes unsigned int and a char as 
arguments and returns a character.
ft_strmapi is to allow the user to apply a custom function to
each character of a string and create a new string
based on the results.
*/