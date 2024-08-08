/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:46:15 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/08 11:15:23 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*checks if a given string contains any digit.
If no digits, status remains true*/
static bool	no_digit_found(char *str)
{
	int		i;
	bool	status;

	i = 0;
	status = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			status = false;
		i++;
	}
	return (status);
}

/*converts an array of strings representing numbers(rgb_to_convert) into
an array of integers(rgb)*/
static int	*convert_and_add_rgb(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit_found(rgb_to_convert[i]))
		{
			free_array_2d((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	free_array_2d((void **)rgb_to_convert);
	return (rgb);
}

/*checks the first three strings in the map array to ensure
that they contain only digits,whitespace characters, or newline characters.
If any invalid character is found, it returns 0. If all characters are
valid, it returns 1.*/
int	col_only_digits(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_isdigit(map[i][j])
				&& !ft_isspace(map[i][j]) && map[i][j] != '\n')
			{
				if (DEBUG)
					printf("Color debugger: %s\n", map[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*processes a comma-separated string representing RGB values.
It splits the string into parts, checks that there are exactly 3 parts, ensures
that each part contains only digits, allocates memory for the RGB values,
and converts the strings to integers.*/
static int	*add_rgb(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		free_array_2d((void **)rgb_to_convert);
		return (0);
	}
	if (col_only_digits(rgb_to_convert) == 0)
	{
		free_array_2d((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		print_error("Memory allocation failed");
		return (0);
	}
	return (convert_and_add_rgb(rgb_to_convert, rgb));
}

/*function processes a line of input to add ceiling or floor color data
to a t_data structure It checks for invalid characters, determines whether
the color data is for the ceiling ('C') or floor ('F'), and calls the
`add_rgb` function to convert and add the RGB values. If any step fails,
it prints an error message and returns `FAILURE`. If successful, it returns `SUCCESS`.*/
int	add_colors(t_data *data, char *line, int j)
{
	if (line[j + 1] && ft_isprint_no_space(line[j + 1]))
		return (print_error("Colors: Invalid F or C data"), FAILURE);
	if (!data->col_ceiling && line[j] == 'C')
	{
		data->col_ceiling = add_rgb(line + j + 1);
		if (data->col_ceiling == 0)
			return (print_error("Colors: Invalid F or C data"), FAILURE);
	}
	else if (!data->col_floor && line[j] == 'F')
	{
		data->col_floor = add_rgb(line + j + 1);
		if (data->col_floor == 0)
			return (print_error("Colors: Invalid F data"), FAILURE);
	}
	else
		return (print_error("Colors: Invalid F or C data"), FAILURE);
	return (SUCCESS);
}
