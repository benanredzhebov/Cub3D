/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:10:43 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/09 15:05:08 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*reads map data from data->cub_file*/
static int	fill_map_2d(t_data *data, char **map, int index)
{
	printf("\nFILL_MAP_2D\n");
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
		printf("Debug: Allocated memory for map[%d]\n", i);
		while (data->cub_file[index][j] && data->cub_file[index][j] != '\n')
		{
			map[i][j] = data->cub_file[index][j];
			j++;
		}
		printf("Debug: Filled map[%d] with data from cub_file[%d]\n", i, index);
		i++;
		index++;
	}
	map[i] = NULL;
	printf("Debug: Set map[%d] to NULL\n", i);
	return (SUCCESS);
}

/*counts lines of map*/
static int	count_map_lines(t_data *data, char **file, int i)
{
	printf("\nCOUNT_MAP_LINES\n");
	int	index_val;
	int	j;
	
	index_val = i;
	printf("Debug: Initial index_val: %d\n", index_val);
	while (file[i])
	{
		j = 0;
		printf("Debug: Processing line %d: %s\n", i, file[i]);
		while (ft_isspace(file[i][j]))
			j++;
		printf("Debug: First non-space character at position %d: %c\n", j, file[i][j]);
		if (file[i][j] && file[i][j] != '1'){
			printf("Debug: Breaking at line %d, character: %c\n", i, file[i][j]);
			break;
		}
		i++;
	}
	data->map->map_end_index = i;
	printf("Debug: map_end_index: %d\n", data->map->map_end_index);
	return (i - index_val);
}

/*checks the map data for any tab characters
i:iterates through the rows of the map
j: iterate through the characters in each row*/
int	no_tabs(t_data *data)
{
	printf("\nNO_TABS\n");
	char	**map;
	int		i;
	int		j;

	map = data->map->map_data;
	i = 0;
	while (i < data->map->map_height)
	{
		printf("Debug: Checking row %d\n", i);
		j = 0;
		while (map[i][j])
		{
			printf("Debug: Checking map[%d][%d]: %c\n", i, j, map[i][j]);
			if (map[i][j] == '\t'){
				printf("Debug: Tab found at map[%d][%d]\n", i, j);
				return (print_error("Map: Tab instead of space"), FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	retrieve_map_data(t_data *data, char **cub_file, int i)
{
	printf("\nRETRIEVE_MAP_DATA\n");
	if (DEBUG)
		printf("Map start Index: %d\n", i);
	printf("Debug: Calling count_map_lines\n");
	data->map->map_height = count_map_lines(data, cub_file, i);
	if (DEBUG)
		printf("Map height: %d\n", data->map->map_height);
	printf("Debug: Allocating memory for map_data\n");
	data->map->map_data = malloc(sizeof(char *) * (data->map->map_height + 1));
	if (!data->map->map_data)
		return (print_error("Memory allocation failed"), FAILURE);
	printf("Debug: Calling fill_map_2d\n");
	if (fill_map_2d(data, data->map->map_data, i) == FAILURE)
		return (FAILURE);
	printf("Debug: Calling no_tabs\n");
	if (no_tabs(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*processes a map from a file, validates it, adjusts its shape*/
int	add_map(t_data *data, char **cub_file, int i)
{
	printf("\nADD_MAP\n");
	int	j;
	
	if (data->map == NULL)
	{
		data->map = malloc(sizeof(t_map));
		if (!data->map) 
			return(print_error("Error: Failed to allocate memory for map"), FAILURE);
	}
	init_map(data->map);
	printf("Debug: Calling retrieve_map_data\n");
	if (retrieve_map_data(data, cub_file, i) == FAILURE){
		printf("Debug: retrieve_map_data failed\n");
		return (FAILURE);
	}
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
	printf("Debug: Calling validate_walls\n");
	if (validate_walls(data) == FAILURE)
		return (print_error("Map: Should be surrounded by walls"), FAILURE);
	make_map_rectangular(data);
	return (SUCCESS);
}
