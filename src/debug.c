/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:23:11 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/06 14:29:56 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

void	print_array_2d(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i])
	{
		printf("%s\n", array_2d[i]);
		i++;
	}
}

/*prints each string in a 2D array of strings*/
void	print_array_2d_newline(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i])
	{
		printf("line idx %d\n", i);
		printf("%s", array_2d[i]);
		printf("\n");
		i++;
	}
}
