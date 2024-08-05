/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:52:13 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/22 17:12:44 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	unsigned int	i;
	char			*last_occurence;

	last_occurence = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)chr)
			last_occurence = (char *)&str[i];
		i++;
	}
	if ((char)chr == str[i])
		return ((char *)&str[i]);
	return (last_occurence);
}

// int	main(void)
// {
// 	char	str[] = "Benan Redzhebov";
// 	char	chr = 'e';

// 	char	*ptr = ft_strrchr(str, chr);
// 	if (ptr)
// 		printf("L occurence of %c in %s is at index %ld\n",chr, str, ptr - str);
// 	else
// 		printf("%c is not present in %s ", chr, str);
// 	return (0);
// }
