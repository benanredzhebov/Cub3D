/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:20:29 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/20 13:53:04 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h".

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
		// set_dda(ray, data); //have to write the function
		// perform_dda(data, ray); //have to write the function
		// calculate_line_height(ray, data); //have to write the function
		// update_texture_pixels(data, ray, x); //have to write the function
		x++;
	}
	return (SUCCESS);
}
