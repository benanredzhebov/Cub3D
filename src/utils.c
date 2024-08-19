/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:28:16 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/19 11:05:45 by beredzhe         ###   ########.fr       */
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

size_t	ft_strlen_no_newline(const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			len++;
		i++;
	}
	return (len);
}

size_t	find_max_width(t_data *data, int i)
{
	size_t	max_width;

	max_width = ft_strlen_no_newline(data->cub_file[i]);
	while (data->cub_file[i])
	{
		if (ft_strlen_no_newline(data->cub_file[i]) > max_width)
			max_width = ft_strlen_no_newline(data->cub_file[i]);
		i++;
	}
	return (max_width);
}
