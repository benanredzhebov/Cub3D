/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:28:16 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/05 14:03:18 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

bool	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (true);
	return (false);
}

void	print_error(char *error_msg)
{
	printf("\nError:\n%s\n\n", error_msg);
}

/*functions checks if the character c fails within the ASCII range of
printable characters excluding the space 
'!' - is the first printable character after space
'~' - is the last printable character*/
bool	ft_isprint_no_space(int c)
{
	if (c >= '!' && c <= '~')
		return (true);
	else
		return (false);
}