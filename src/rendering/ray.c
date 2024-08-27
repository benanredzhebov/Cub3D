/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42wolfsburg.de> +#+  +:+       +#+        */
/*   demacinema <demacinema@student.42.de>        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

/*Calculate the distance of the ray to the wall.*/
static void	calculate_line_height(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(data->map->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->map->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->map->win_height / 2;
	if (ray->draw_end >= data->map->win_height)
		ray->draw_end = data->map->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = data->player_pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player_pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/*1.Determine which direction (X or Y) the ray should advance.
2.Update the ray's position and side of intersection.
3.Check if the ray is still within map boundaries.
4.Check if the ray has hit a wall.*/
static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > data->map->map_height - 0.25
			|| ray->map_x > data->map->map_width - 1.25)
			break ;
		else if (data->map->map_data[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/*1.step_x:  Determines whether the ray moves to the next or previous column.
2.sidedist_x: Distance to the next vertical(|) grid line.
3.step_y: Determines whether the ray moves to the next or previous row
4.sidedist_y: Distance to the next horizontal(-) grid line.

THIS WAS ON THE TOP OF set_dda:
	// printf("Initial values: dir_x = %f, dir_y = %f, player_pos_x = %f, 
	// player_pos_y = %f, map_x = %d, map_y = %d\n",
    //     ray->dir_x, ray->dir_y, data->player_pos_x, 
	// data->player_pos_y, ray->map_x, ray->map_y);

AND THIS AFTER EACH CASE:
		printf("dir_x < 0: step_x = %d, sidedist_x = %f\n", 
		ray->step_x, ray->sidedist_x);	
*/
static void	set_dda(t_ray *ray, t_data *data)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->player_pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x
			= (ray->map_x + 1.0 - data->player_pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player_pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y
			= (ray->map_y + 1.0 - data->player_pos_y) * ray->deltadist_y;
	}
}

/*1.Camera plane calculation.
2. Direction calculation.
3.Convert the player's position, which grid cell in
the map the player is currently in.(set the initial position
of the ray in the map grid)
4.Calculate the distance the ray must travel in the x and y directions
to pass from one x-side to the next x-side or from one y-side to the next
y-side
printf("Ray %d: x=%2f, camera_x=%.2f, dir_x=%.2f, dir_y=%.2f,
map_x=%d, map_y=%d, deltadist_x=%.2f, deltadist_y=%.2f\n",
			x, ray->camera_x, ray->dir_x, ray->dir_y, ray->map_x, 
			ray->map_y, ray->deltadist_x, ray->deltadist_y);*/
static void	init_raycasting_info(int x, t_ray *ray, t_data *data)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = data->player_dir_x + data->player_plane_x * ray->camera_x;
	ray->dir_y = data->player_dir_y + data->player_plane_y * ray->camera_x;
	ray->map_x = (int)data->player_pos_x;
	ray->map_y = (int)data->player_pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

int	raycasting(t_data *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = &data->ray;
	while (x < WIN_WIDTH)
	{
		init_raycasting_info(x, ray, data);
		set_dda(ray, data);
		perform_dda(data, ray);
		calculate_line_height(ray, data);
		update_texture_pixels(data, ray, x);
		x++;
	}
	return (SUCCESS);
}
