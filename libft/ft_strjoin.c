/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:42:12 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/17 16:44:09 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	counter;
	size_t	sec_counter;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = malloc(sizeof(char) * size);
	if (newstr == 0)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		newstr[counter] = s1[counter];
		counter++;
	}
	sec_counter = 0;
	while (s2[sec_counter] != '\0')
	{
		newstr[counter + sec_counter] = s2[sec_counter];
		sec_counter++;
	}
	newstr[counter + sec_counter] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	char	s1[] = "Dorukhan";
// 	char	s2[] = "Defne";
// 	char	*newstr;

// 	newstr = ft_strjoin(s1, s2);
// 	printf("The new string is: %s\n", newstr);
// 	return (0);
// }
