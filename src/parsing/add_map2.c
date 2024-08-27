/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42wolfsburg.de> +#+  +:+       +#+        */
/*   demacinema <demacinema@student.42.de>        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

static void	fill_line_with_ones(char *new_line, t_data *data)
{
	int	j;

	j = 0;
	while (j < data->map->map_width)
	{
		new_line[j] = '1';
		j++;
	}
	new_line[j] = '\0';
}

static void	copy_line(char *new_line, char *old_line)
{
	int	j;

	j = 0;
	while (old_line[j])
	{
		if (old_line[j] != ' ')
			new_line[j] = old_line[j];
		j++;
	}
}

void	make_map_rectangular(t_data *data)
{
	int		i;
	char	*new_line;

	i = 0;
	while (i < data->map->map_height)
	{
		new_line = (char *)malloc(sizeof(char) * (data->map->map_width + 1));
		if (!new_line)
		{
			print_error("Memory allocation failed");
			return ;
		}
		fill_line_with_ones(new_line, data);
		copy_line(new_line, data->map->map_data[i]);
		free(data->map->map_data[i]);
		data->map->map_data[i] = new_line;
		i++;
	}
}
