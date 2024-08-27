/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:44:57 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/25 23:16:56 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while ((ft_check(s1[start], set) == 0) && (s1[start] != '\0'))
		start++;
	while ((ft_check(s1[end - 1], set) == 0) && (end > start))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	s1[] = "  Hello!   ";
// 	char	set[] = " ";

// 	char *trimmed = ft_strtrim(s1, set);
// 	if (trimmed != NULL)
// 	{
// 		printf("Original string: \"%s\"\n", s1);
// 		printf("Trimmed string: \"%s\"\n", trimmed);
// 		free(trimmed);
// 	}
// 	else
// 		printf("Memory allocation error in ft_strtrim\n");
// 	return (0);
// }
