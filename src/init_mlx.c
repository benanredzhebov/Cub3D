/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:21:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/14 22:07:08 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		print_error("Mlx: Startup error");
		clean_exit(data, FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win_ptr)
	{
		print_error("Mlx: Window error");
		clean_exit(data, FAILURE);
	}
}
