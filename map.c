/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void read_map(const char *filename, t_map *map)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	int row = 0;
	int max_cols = 0;

	// Allocate memory for the map data
	map->map_data = (char **)malloc(MAX_ROWS * sizeof(char *));
	int i = 0;
	while (i < MAX_ROWS)
	{
		map->map_data[i] = (char *)malloc(MAX_COLS * sizeof(char));
		ft_memset(map->map_data[i], 0, MAX_COLS);
		i++;
	}

	while ((line = get_next_line(fd)) && row < MAX_ROWS)
	{
		int len = ft_strlen(line);
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0'; // Remove newline character
			len--;
		}
		ft_strlcpy(map->map_data[row], line, MAX_COLS);
		if (len > max_cols)
		{
			max_cols = len;
		}
		row++;
		free(line); // Free the line allocated by GNL
	}

	map->height = row * TILE_SIZE;
	map->width = max_cols * TILE_SIZE;
	printf("Map dimensions: %dx%d\n", map->width, map->height);

	i = 0;
	while (i < row)
	{
		printf("%s\n", map->map_data[i]);
		int j = 0;
		while (j < max_cols)
		{
			if (map->map_data[i][j] != '0' && map->map_data[i][j] != '1' && map->map_data[i][j] != 'N' \
			&& map->map_data[i][j] != 'S' && map->map_data[i][j] != 'E' && map->map_data[i][j] != 'W' && map->map_data[i][j] != '\0')
			{
				fprintf(stderr, "Error: Invalid character '%c' found in map at row %d, col %d\n", map->map_data[i][j], i, j);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}

	if (close(fd) == -1)
	{
		perror("Failed to close file");
		exit(EXIT_FAILURE);
	}
}

























// void read_map(const char *filename, char map[MAX_ROWS][MAX_COLS], int *rows, int *cols)
// {
// 	int fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Failed to open file");
// 		exit(EXIT_FAILURE);
// 	}

// 	char *line = NULL;
// 	int row = 0;
// 	int max_cols = 0;

// 	// Initialize the map array to ensure no garbage values
// 	int i = 0;
// 	while (i < MAX_ROWS)
// 	{
// 		ft_memset(map[i], 0, MAX_COLS);
// 		i++;
// 	}

// 	while ((line = get_next_line(fd)) && row < MAX_ROWS)
// 	{
// 		int len = ft_strlen(line);
// 		if (line[len - 1] == '\n')
// 		{
// 			line[len - 1] = '\0'; // Remove newline character
// 			len--;
// 		}
// 		ft_strlcpy(map[row], line, MAX_COLS);
// 		if (len > max_cols)
// 		{
// 			max_cols = len;
// 		}
// 		row++;
// 		free(line); // Free the line allocated by GNL
// 	}

// 	*rows = row;
// 	*cols = max_cols;

// 	i = 0;
// 	while (i < row)
// 	{
// 		printf("%s\n", map[i]);
// 		int j = 0;
// 		while (j < max_cols)
// 		{
// 			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' \
// 			&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != '\0')
// 			{
// 				fprintf(stderr, "Error: Invalid character '%c' found in map at row %d, col %d\n", map[i][j], i, j);
// 				exit(EXIT_FAILURE);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}

// 	if (close(fd) == -1)
// 	{
// 		perror("Failed to close file");
// 		exit(EXIT_FAILURE);
// 	}
// }