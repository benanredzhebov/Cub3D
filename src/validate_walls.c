/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:25:09 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/20 11:52:22 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*
dr: "delta row"
used to determine the row index for the next cell to visit during DFS,
each value represents a move in the vertical direction (up or down),
values are set to -1, 0, 1, 0 to represent:
	moving up, 
	(no vertical movement), 
	moving down, 
	(no vertical movement)
	
dc: "delta column"
used to determine the column index for the next cell to visit during DFS,
each value represents a move in the horizontal direction (left or right),
values are set to 0, 1, 0, -1 to represent
	(no horizontal movement),
	moving right, 
	(no horizontal movement), 
	moving left

using these arrays in the dfs_recursive function, 
loop through them to check all four possible directions from the current cell.
example: r + map_data->dr[i] and c + map_data->dc[i] gives us the indices of 
the cell in the direction specified by i from the current cell (r, c)
*/
void	init_map_data(t_dfs *map_data, t_data *data, char **map_clone)
{
	map_data->map = map_clone;
	map_data->h = data->map->map_height;
	map_data->w = data->map->map_width;
	map_data->valid = 1;
	map_data->dr[0] = -1;
	map_data->dr[1] = 0;
	map_data->dr[2] = 1;
	map_data->dr[3] = 0;
	map_data->dc[0] = 0;
	map_data->dc[1] = 1;
	map_data->dc[2] = 0;
	map_data->dc[3] = -1;
}

int	is_last_char_one(const char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = len - 1;
	while (i >= 0 && line[i] == ' ')
		i--;
	if (i >= 0 && ft_isprint_no_space(line[i]))
	{
		if (line[i] == '1')
			return (SUCCESS);
		return (FAILURE);
	}
	return (FAILURE);
}

/*
performs depth-first search on the map from a given starting point
checks whether a given point is within the map and whether it's traversable.
If a point is outside the map or not traversable, 
the map is marked as invalid.

two integers (r and c) representing current position in the map
*/
void	dfs_recursive(t_dfs *map_data, int r, int c)
{
	int	i;

	if (r < 0 || c < 0 || r >= map_data->h || c >= map_data->w)
	{
		map_data->valid = 0;
		return ;
	}
	if (map_data->map[r][c] == '1' || map_data->map[r][c] == '.')
		return ;
	map_data->map[r][c] = '.';
	i = -1;
	while (++i < 4)
		dfs_recursive(map_data, r + map_data->dr[i], c + map_data->dc[i]);
}

/*
runs the depth-first search algorithm on every valid starting point on the map.
if any of the searches result in an invalid map, 
it stops the search and returns 0
*/
int	dfs(t_data *data, char **map_clone)
{
	t_dfs	map_data;
	int		i;
	int		j;

	init_map_data(&map_data, data, map_clone);
	i = -1;
	while (++i < map_data.h)
	{
		j = -1;
		while (++j < map_data.w)
		{
			if (map_data.map[i][j] == '0' || map_data.map[i][j] == 'N'
				|| map_data.map[i][j] == 'E' || map_data.map[i][j] == 'W'
				|| map_data.map[i][j] == 'S')
				dfs_recursive(&map_data, i, j);
		}
	}
	return (map_data.valid);
}

/*function ensures that the map's walls are valid
by checking the last character of each row and performing
a DFS validation. It clones the map data for the DFS process.*/
int	validate_walls(t_data *data)
{
	char	**map_clone;
	int		i;
	int		valid;

	i = 0;
	while (i < data->map->map_height)
	{
		if (is_last_char_one(data->map->map_data[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	map_clone = malloc(data->map->map_height * sizeof(char *));
	i = -1;
	while (++i < data->map->map_height)
		map_clone[i] = ft_strdup2(data->map->map_data[i], data->map->map_width);
	valid = dfs(data, map_clone);
	i = -1;
	while (++i < data->map->map_height)
		free(map_clone[i]);
	free(map_clone);
	if (valid)
		return (SUCCESS);
	return (FAILURE);
}
