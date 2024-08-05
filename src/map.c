/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/05 10:22:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

void	open_file(const char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
}

void	process_map(int fd, t_map map[MAP_HEIGHT][MAP_WIDTH])
{
	int		x;
	int		y;
	char	buffer[MAP_WIDTH + 2];
	ssize_t	bytes_read;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		bytes_read = read(fd, buffer, MAP_WIDTH + 1);
		if (bytes_read <= 0)
		{
			perror("Error reading map file");
			close(fd);
			exit(EXIT_FAILURE);
		}
		buffer[MAP_WIDTH] = '\0';
		x = 0;
		while (x < MAP_WIDTH)
		{
			map[y][x] = buffer[x] - '0';
			++x;
		}
		++y;
	}
	close(fd);
}

void	read_map(const char *filename, t_map map[MAP_HEIGHT][MAP_WIDTH])
{
	int		fd;

	open_file(filename, &fd);
	process_map(fd, map);
}

void	load_map(const char *filename)
{
	t_map	map[MAP_HEIGHT][MAP_WIDTH];

	read_map(filename, map);
	// print_map(map);
}

// void	print_map(t_map map[MAP_HEIGHT][MAP_WIDTH])
// {
// 	int		x;
// 	int		y;

// 	printf("Loaded map:\n");
// 	y = 0;
// 	while (y < MAP_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < MAP_WIDTH)
// 		{
// 			printf("%d", map[y][x]);
// 			++x;
// 		}
// 		printf("\n");
// 		++y;
// 	}
// }