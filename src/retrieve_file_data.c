/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_file_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:18:20 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/09 09:31:18 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*function extracts a texture path from a given line of text starting at index j.
It skips leading whitespace, determines the length of the path,
allocates memory for it, copies the path characters, skips trailing
whitespace, and checks for any invalid characters. if the path is valid,
it returns the allocated path*/
static char	*add_tex_path(char *line, int j)
{
	printf("\nADD_TEX_PATH\n");
	int		len;
	int		i;
	char	*path;

	printf("Debug: Entering add_tex_path with line = %s, j = %d\n", line, j);
	while (line[j] && ft_isspace(line[j])){
		printf("Debug: Skipping space, new j = %d\n", j);
		j++;
	}
	len = j;
	while (line[len] && !ft_isspace(line[j])){
		len++;
		printf("Debug: Calculating length, new len = %d\n", len);
	}
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (!ft_isspace(line[j]) && line[j] != '\n')){
		path[i++] = line[j++];
		printf("Debug: Copying character, path[%d] = %c, new j = %d\n", i - 1, path[i - 1], j);
	}
	path[i] = '\0';
	printf("Debug: Final path = %s\n", path);
	while (line[j] && (ft_isspace(line[j]))){
		j++;
		printf("Debug: Skipping trailing space, new j = %d\n", j);
	}
	if (line[j] && line[j] != '\n')
	{
		printf("Debug: Invalid character after path, line[%d] = %c\n", j, line[j]);
		free(path);
		path = NULL;
	}
	printf("Debug: Returning path = %s\n", path);
	return (path);
}

/*function processes a line of text to identify and assign texture
paths to the `data` structure. It ensures that the texture identifiers
are valid and that no invalid characters follow the identifier.
If any condition fails, it prints an error message and returns
`FAILURE`. If successful, it returns `SUCCESS`.*/
static int	add_textures(t_data *data, char *line, int j)
{
	printf("\nADD_TEXTURES\n");
	printf("Debug: Entering add_textures with line = %s, j = %d\n", line, j);
	if (line[j + 2] && ft_isprint_no_space(line[j + 2])){
		printf("Debug: Invalid texture at line[%d + 2] = %c\n", j, line[j + 2]);
		return (print_error("Textures: Invalid"), FAILURE);
	}
	if (line[j] == 'N' && line[j + 1] == 'O' && !(data->tex_north)){
		printf("Debug: Adding north texture\n");
		data->tex_north = add_tex_path(line, j + 2);
	}
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(data->tex_south)){
		printf("Debug: Adding south texture\n");
		data->tex_south = add_tex_path(line, j + 2);
	}
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(data->tex_west)){
		printf("Debug: Adding west texture\n");
		data->tex_west = add_tex_path(line, j + 2);
	}
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(data->tex_east)){
		printf("Debug: Adding east texture\n");
		data->tex_east = add_tex_path(line, j + 2);
	}
	else
		return (print_error("Textures: Invalid"), FAILURE);
	return (SUCCESS);
}

/*processes a line from the .cub file, skipping over spaces and newlines,
and then performs different actions based on the type of the character encountered*/
static int	skip_spaces(t_data *data, char **cub_file, int i, int j)
{
	printf("\nSKIP_SPACES\n");
	printf("Debug: Entering skip_spaces with i = %d, j = %d\n", i, j);
	while (ft_isspace(cub_file[i][j]) || cub_file[i][j] == '\n'){
		printf("Debug: Skipping space/newline, new j = %d\n", j);
		j++;
	}
	printf("Debug: After skipping spaces, cub_file[%d][%d] = %c\n", i, j, cub_file[i][j]);
	if (ft_isprint_no_space(cub_file[i][j]) && !ft_isdigit(cub_file[i][j]))
	{
		if (cub_file[i][j + 1] && ft_isprint_no_space(cub_file[i][j + 1])
			&& !ft_isdigit(cub_file[i][j]))
		{
			printf("Debug: Adding texture at cub_file[%d][%d]\n", i, j);
			if (add_textures(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
			return (TEXTURE_ADDED);
		}	
		else
		{
			printf("Debug: Adding color at cub_file[%d][%d]\n", i, j);
			if (add_colors(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
			return (TEXTURE_ADDED);
		}	
	}
	else if (ft_isdigit(cub_file[i][j]))
	{
		printf("Debug: Adding map at cub_file[%d][%d]\n", i, j);
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
	printf("\nRETRIEVE_FILE_DATA\n");
	int	i;
	int	j;
	int	status;

	i = 0;
	while (cub_file[i])
	{
		j = 0;
		while (cub_file[i][j])
		{
			printf("Debug: Processing cub_file[%d][%d] = %c\n", i, j, cub_file[i][j]);
			status = skip_spaces(data, cub_file, i, j);
			printf("Debug: skip_spaces returned %d\n", status);
			if (status == FAILURE)
				return (FAILURE);
			else if (status == SUCCESS)
				return (SUCCESS);
			else if (status == TEXTURE_ADDED)
				break;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
