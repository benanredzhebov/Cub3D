/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycharles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void display_raycast(t_data *data)
{
	double start_angle = data->player.angle - (FOV / 2);
	double angle_increment = FOV / NUM_RAYS;
	double current_angle = start_angle;
	int ray_count = 0;

	while (ray_count < NUM_RAYS)
	{
		double ray_dir_x = cos(current_angle * DEG2RAD);
		double ray_dir_y = sin(current_angle * DEG2RAD);

		// Current position of the ray
		double ray_x = data->player.x;
		double ray_y = data->player.y;

		// Length of the ray's step in each direction
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);

		// Step direction and initial side distance
		int step_x, step_y;
		double side_dist_x, side_dist_y;

		int map_x = (int)ray_x;
		int map_y = (int)ray_y;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (ray_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - ray_x) * delta_dist_x;
		}

		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (ray_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - ray_y) * delta_dist_y;
		}

		// Perform DDA
		while (map_x >= 0 && map_x < data->map->width && map_y >= 0 && map_y < data->map->height)
		{
			// Check if the current position is a wall
			if (is_wall(map_x, map_y, data))
				break ; // Stop the ray when it meets a wall

			// put_pixel_to_image(data, map_x, map_y, color);
			mlx_pixel_put(data->mlx, data->win, map_x, map_y, BLACK);

			// Move to the next map square
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
			}
		}

		current_angle += angle_increment;
		ray_count++;
	}
}


// void display_raycast(t_data *data)
// {
// 	// Calculate the ray's direction using player's position and angle directly from data
// 	double ray_dir_x = cos((data->player.angle) * DEG2RAD);
// 	double ray_dir_y = sin((data->player.angle) * DEG2RAD);

// 	// Current position of the ray
// 	double ray_x = data->player.x;
// 	double ray_y = data->player.y;

// 	// Length of the ray's step in each direction
// 	double delta_dist_x = fabs(1 / ray_dir_x);
// 	double delta_dist_y = fabs(1 / ray_dir_y);

// 	// Step direction and initial side distance
// 	int step_x, step_y;
// 	double side_dist_x, side_dist_y;

// 	int map_x = (int)ray_x;
// 	int map_y = (int)ray_y;

// 	if (ray_dir_x < 0)
// 	{
// 		step_x = -1;
// 		side_dist_x = (ray_x - map_x) * delta_dist_x;
// 	}
// 	else
// 	{
// 		step_x = 1;
// 		side_dist_x = (map_x + 1.0 - ray_x) * delta_dist_x;
// 	}

// 	if (ray_dir_y < 0)
// 	{
// 		step_y = -1;
// 		side_dist_y = (ray_y - map_y) * delta_dist_y;
// 	}
// 	else
// 	{
// 		step_y = 1;
// 		side_dist_y = (map_y + 1.0 - ray_y) * delta_dist_y;
// 	}

// 	// Perform DDA
// 	while (map_x >= 0 && map_x < data->map->width && map_y >= 0 && map_y < data->map->height)
// 	{
// 		// Check if the current position is a wall
// 		if (is_wall(map_x, map_y, data))
// 			break ; // Stop the ray when it meets a wall

// 		// put_pixel_to_image(data, map_x, map_y, color);
// 		mlx_pixel_put(data->mlx, data->win, map_x, map_y, BLACK);

// 		// Move to the next map square
// 		if (side_dist_x < side_dist_y)
// 		{
// 			side_dist_x += delta_dist_x;
// 			map_x += step_x;
// 		}
// 		else
// 		{
// 			side_dist_y += delta_dist_y;
// 			map_y += step_y;
// 		}
// 	}
// }
