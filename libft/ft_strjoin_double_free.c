/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_double_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:59:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/25 10:26:15 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function, `ft_strjoin_double_free`,
is designed to concatenate two strings (`s1` and `s2`),
allocate memory for the new string, and then free the
memory of both input strings.*/
char	*ft_strjoin_double_free(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !*s1)
	{
		str = ft_strdup(s2);
		free((void *)s2);
		return (str);
	}
	if (!s2 || !*s2)
	{
		str = ft_strdup(s1);
		free((void *)s1);
		return (str);
	}
	str = (char *)ft_calloc(1, sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	free((void *)s1);
	ft_strcat(str, s2);
	free((void *)s2);
	return (str);
}
