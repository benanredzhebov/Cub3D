/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:10:43 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/21 15:08:15 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*reads map data from data->cub_file*/
static int	fill_map_2d(t_data *data, char **map, int index)
{
	int		i;
	int		j;

	data->map->map_width = find_max_width(data, index);
	if (DEBUG)
		printf("Map max width: %d\n", data->map->map_width);
	i = 0;
	while (i < data->map->map_height)
	{
		j = 0;
		map[i] = ft_calloc(sizeof(char), (data->map->map_width + 1));
		if (!map[i])
			return (print_error("Memory allocation failed"), FAILURE);
		while (data->cub_file[index][j] && data->cub_file[index][j] != '\n')
		{
			map[i][j] = data->cub_file[index][j];
			j++;
		}
		i++;
		index++;
	}
	map[i] = NULL;
	return (SUCCESS);
}

/*counts lines of map*/
static int	count_map_lines(t_data *data, char **file, int i)
{
	int	index_val;
	int	j;

	index_val = i;
	while (file[i])
	{
		j = 0;
		while (ft_isspace(file[i][j]))
			j++;
		if (file[i][j] && file[i][j] != '1')
			break ;
		i++;
	}
	data->map->map_end_index = i;
	return (i - index_val);
}

/*checks the map data for any tab characters
i:iterates through the rows of the map
j: iterate through the characters in each row*/
int	no_tabs(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map->map_data;
	i = 0;
	while (i < data->map->map_height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\t')
				return (print_error("Map: Tab instead of space"), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	retrieve_map_data(t_data *data, char **cub_file, int i)
{
	if (DEBUG)
		printf("Map start IDX: %d\n", i);
	data->map->map_height = count_map_lines(data, cub_file, i);
	if (DEBUG)
		printf("Map height: %d\n", data->map->map_height);
	data->map->map_data = malloc(sizeof(char *) * (data->map->map_height + 1));
	if (!data->map->map_data)
		return (print_error("Memory allocation failed"), FAILURE);
	if (fill_map_2d(data, data->map->map_data, i) == FAILURE)
		return (FAILURE);
	if (no_tabs(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*processes a map from a file, validates it, adjusts its shape*/
int	add_map(t_data *data, char **cub_file, int i)
{
	int	j;

	// data->map = malloc(sizeof(t_map));
	// if (!data->map)
	// 	return (print_error("Failed to allocation memory for map!"), FAILURE);
	// init_map(data->map);
	if (retrieve_map_data(data, cub_file, i) == FAILURE)
		return (FAILURE);
	if (DEBUG)
	{
		printf("\nLoaded map (**map before filling spaces):\n");
		j = 0;
		while (j < data->map->map_height)
		{
			printf("%s\n", data->map->map_data[j]);
			j++;
		}
	}
	if (validate_walls(data) == FAILURE)
		return (print_error("Map: Should be surrounded by walls"), FAILURE);
	make_map_rectangular(data);
	return (SUCCESS);
}
