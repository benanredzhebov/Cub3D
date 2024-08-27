/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_file_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:18:20 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/27 09:42:26 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

/*function extracts a texture path from a given line of text starting at
index j.
It skips leading whitespace, determines the length of the path,
allocates memory for it, copies the path characters, skips trailing
whitespace, and checks for any invalid characters. if the path is valid,
it returns the allocated path*/
static char	*add_tex_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && ft_isspace(line[j]))
		j++;
	len = j;
	while (line[len] && !ft_isspace(line[j]))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (!ft_isspace(line[j]) && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (ft_isspace(line[j])))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

/*function processes a line of text to identify and assign texture
paths to the `data` structure. It ensures that the texture identifiers
are valid and that no invalid characters follow the identifier.
If any condition fails, it prints an error message and returns
`FAILURE`. If successful, it returns `SUCCESS`.*/
static int	add_textures(t_data *data, char *line, int j)
{
	if (line[j + 2] && ft_isprint_no_space(line[j + 2]))
		return (print_error("Textures: Invalid"), FAILURE);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(data->tex_north))
		data->tex_north = add_tex_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(data->tex_south))
		data->tex_south = add_tex_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(data->tex_west))
		data->tex_west = add_tex_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(data->tex_east))
		data->tex_east = add_tex_path(line, j + 2);
	else
		return (print_error("Textures: Invalid"), FAILURE);
	return (SUCCESS);
}

/*processes a line from the .cub file, skipping over spaces and newlines,
and then performs different actions based on the type of the character
encountered*/
static int	skip_spaces(t_data *data, char **cub_file, int i, int j)
{
	while (ft_isspace(cub_file[i][j]) || cub_file[i][j] == '\n')
		j++;
	if (ft_isprint_no_space(cub_file[i][j]) && !ft_isdigit(cub_file[i][j]))
	{
		if (cub_file[i][j + 1] && ft_isprint_no_space(cub_file[i][j + 1])
			&& !ft_isdigit(cub_file[i][j]))
		{
			if (add_textures(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
			return (TEXTURE_ADDED);
		}
		else
		{
			if (add_colors(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
			return (TEXTURE_ADDED);
		}
	}
	else if (ft_isdigit(cub_file[i][j]))
	{
		if (add_map(data, cub_file, i) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	return (42);
}

/*processes each character in a 2D array of strings(cub_file)
and performs acions based on the return value of skip_spaces */
int	retrieve_file_data(t_data *data, char **cub_file)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (cub_file[i])
	{
		j = 0;
		while (cub_file[i][j])
		{
			status = skip_spaces(data, cub_file, i, j);
			if (status == FAILURE)
				return (FAILURE);
			else if (status == SUCCESS)
				return (SUCCESS);
			else if (status == TEXTURE_ADDED)
				break ;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
