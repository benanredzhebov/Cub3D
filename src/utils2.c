/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:36:08 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/08 09:25:55 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

char	*ft_strdup2(const char *s1, int len)
{
	char *copy;
	
	copy = ft_calloc(len + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, (ft_strlen(s1) + 1));
	return (copy);
}

int	open_file(char *filepath, t_data *data)
{
	int	fd;
	
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		print_error("The file could not be opened!");
		clean_exit(data, FAILURE);
	}
	return (fd);
}
