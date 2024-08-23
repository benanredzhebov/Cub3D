/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:34:15 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/23 09:41:32 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

int	parsing(t_data *data, char **av)
{
	char	**cub_file;

	if (validate_cub_file(av[1]) == FAILURE)
		exit(FAILURE);
	save_cub(av[1], data);
	cub_file = data->cub_file;
	if (retrieve_file_data(data, cub_file) == FAILURE)
		return (FAILURE);
	if (DEBUG)
	{
		printf("\nSaved map (**map after filling spaces):\n");
		print_array_2d_newline(data->map->map_data);
		printf("\n");
		printf("Saved textures:\n");
		printf("South: %s\n", data->tex_south);
		printf("North: %s\n", data->tex_north);
		printf("West: %s\n", data->tex_west);
		printf("East: %s\n", data->tex_east);
	}
	if (validate_map(data, data->map->map_data) == FAILURE)
		return (FAILURE);
	if (validate_textures(data) == FAILURE)
		return (FAILURE);
	add_player_direction(data);
	return (SUCCESS);
}
