/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:32:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/28 09:13:08 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

/*clean up resources and exit the program with a specified status*/
// void	clean_exit(t_data *data, int exitstatus)
// {
// 	if (data)
// 	{
// 		if (data->mlx_ptr && data->win_ptr)
// 		{
// 			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 			data->win_ptr = NULL;
// 		}	
// 		free_data(data);
// 		free(data->mlx_ptr);
// 		data->mlx_ptr = NULL;
// 	}
// 	exit(exitstatus);
// }

void	clean_exit(t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data)
	{
		if (data->win_ptr && data->mlx_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			mlx_loop_end(data->mlx_ptr);
			free(data->mlx_ptr);
		}
	}
	free_data(data);
	exit(code);
}

int	quit_cub3d(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}
