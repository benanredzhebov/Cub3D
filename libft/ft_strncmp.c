/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:56:29 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/22 17:49:45 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && str1[i] != '\0' \
	&& str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

// int main()
// {
// 	char str1[20] = "hel1o";
// 	char str2[20] = "hel1o";
// 	int result;

// 	//Assigning the value to the string str1
// 	//strcpy(str1, "hello");

// 	//Assigning the value to the string str2
// 	//strcpy(str2, "helLO WORLD");

// 	//This will compare the first 3 characters
// 	result = ft_strncmp(str1, str2, 4);

// 	if(result > 0) 
// 	{
// 		printf("str1 is greater than str2");
// 	} 
// 	else if(result < 0)
// 	{
// 		printf("str1 is less than str2"); 
// 	}
// 	else
// 		printf("Both the strings str1 and str2 are equal");

// 	return 0;
// }
