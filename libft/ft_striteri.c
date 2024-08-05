/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:15:04 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/24 15:09:00 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void print_index_char(unsigned int index, char *character)
// {
//     printf("Index: %u, Character: %c\n", index, *character);
// }

// int main(void)
// {
// 	char str[] = "Benan";

// 	printf("Original string: %s\n", str);

// 	printf("Applying ft_striteri:\n");

// 	ft_striteri(str, &print_index_char);

// 	return 0;
// }
