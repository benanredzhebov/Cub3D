/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:27:04 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/10 12:33:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/* 
void function => CAN TAKE ANY TYPE,
so we need to cast like:
free_array_2d((void **)data->mapdata.file_content);

should not set the array_2d pointer to NULL inside
free_array_2d function - doing so will not affect 
original pointer passed from the calling function.
*/
void	free_array_2d(void **array_2d)
{
	int	i;

	if (!array_2d)
		return ;
	i = 0;
	while (array_2d[i])
	{
		free(array_2d[i]);
		i++;
	}
	free(array_2d);
	array_2d = NULL;
}

/*release memory and resources associated with the cub
component of a 't_data' structure*/
void	free_cub(t_data *data)
{
	data->cub_path = NULL;
	if (data->cub_file)
	{
		free_array_2d((void **)data->cub_file);
		data->cub_file = NULL;
	}
	if (data->cub_fd > 0)
		close(data->cub_fd);
}

/*relese memory allocated for texture-related data within a
't_data' structure*/
void	free_textures(t_data *data)
{
	if (data->tex_east)
	{
		free(data->tex_east);
		data->tex_east = NULL;
	}
	if (data->tex_north)
	{
		free(data->tex_north);
		data->tex_north = NULL;
	}
	if (data->tex_south)
	{
		free(data->tex_south);
		data->tex_south = NULL;
	}
	if (data->tex_west)
	{
		free(data->tex_west);
		data->tex_west = NULL;
	}
	free_array_2d((void **)data->textures);
	free_array_2d((void **)data->tex_pixels);
}

void	free_colors(t_data *data)
{
	if (data->col_ceiling)
	{
		free(data->col_ceiling);
		data->col_ceiling = NULL;
	}
	if (data->col_floor)
	{
		free(data->col_floor);
		data->col_floor = NULL;
	}
}

/*release memory allocated for a 't_data' structure*/
void	free_data(t_data *data)
{
	free_cub(data);
	free_textures(data);
	free_colors(data);
	if (data->map->map_data)
	{
		free_array_2d((void **)data->map->map_data);
		data->map->map_data = NULL;
	}
}
