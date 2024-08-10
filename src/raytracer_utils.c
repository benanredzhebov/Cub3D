/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/10 23:42:56 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

// // Function to put a pixel on the screen at (x, y) with the specified color
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
// 	{

// 		dst = data->data_addr \
// 			+ (y * data->size_line + x * (data->bpp / 8));
// 		*(unsigned int *)dst = color;
// 	}
// }

// // Function to create a color value from individual components
// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// Function to check if a given (x, y) position is a wall in the map
// int	is_wall(int x, int y, int map[MAP_HEIGHT][MAP_WIDTH])
// {
// 	int	map_x;
// 	int	map_y;

// 	map_x = x / TILE_SIZE;
// 	map_y = y / TILE_SIZE;

// 	if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
// 		return (1);
// 	return (map[map_y][map_x]);
// }

// Function to check if a given (x, y) position is a wall in the map
int	is_wall(int r, int c, t_data *data)
{
	int	map_r;
	int	map_c;

	map_r = r / TILE_SIZE;
	map_c = c / TILE_SIZE;

	if (map_r < 0 || map_r >= data->map->map_width || map_c < 0 || map_c >= data->map->map_height)
		return (1);
	return (data->map->map_data[map_c][map_r]);
}