/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:08:58 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/20 11:03:16 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*ensures that there are no non-whitespace characters after the end of
the map section in the file*/
static int	check_map_is_at_the_end(t_data *data)
{
	int	i;
	int	j;

	i = data->map->map_end_index;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (!ft_isspace(data->cub_file[i][j])
				&& data->cub_file[i][j] != '\n')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/*locate the player's initial position on a map and update the player's
coordinates in the 'data' structure*. It also replaces the player's
position on the map with a '0' to indicate an empty space*/
static int	add_player_position(t_data *data, char **map)
{
	int	i;
	int	j;

	if (data->player_dir == '0')
		return (print_error("Map: no player found"), FAILURE);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				data->player_x = j;
				data->player_y = i;
				data->player_pos_x = (double)j + 0.5;
				data->player_pos_y = (double)i + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/*1.Initializes counters and sets the initial player direction to '0'.
2.Iterates through each character in the map.
3.Skips whitespace characters.
4.Validates that each character is one of the allowed characters
("1", "0", "N", "E", "W", "S").
5.Ensures there is only one player character ("N", "E", "W", "S") in the map.
6.Sets the player direction if a player character is found and no player
direction has been set yet.
7.Returns SUCCESS if all checks pass, otherwise returns FAILURE with an
appropriate error message.*/
static int	check_map_elements(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->player_dir = '0';
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_isspace(data->map->map_data[i][j]))
				j++;
			if (!(ft_strchr("10NEWS", map[i][j])))
				return (print_error("Map: Contains invalid character"), \
				FAILURE);
			if (ft_strchr ("NEWS", map[i][j]) && data->player_dir != '0')
				return (print_error("Map: more than one player"), FAILURE);
			if (ft_strchr ("NEWS", map[i][j]) && data->player_dir == '0')
				data->player_dir = map[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_map(t_data *data, char **map)
{
	if (!data->map->map_data)
		return (print_error("Map:Not found"), FAILURE);
	if (data->map->map_height < 3)
		return (print_error("Map: Should contain at least 3 lines"), FAILURE);
	if (check_map_elements(data, map) == FAILURE)
		return (FAILURE);
	if (add_player_position(data, map) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(data) == FAILURE)
		return (print_error("Map: Should be the last element in file"), \
		FAILURE);
	return (SUCCESS);
}
