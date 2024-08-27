/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42wolfsburg.de> +#+  +:+       +#+        */
/*   demacinema <demacinema@student.42.de>        +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

/*initialize an image structure with a new image
created using MiniLibx*/
void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_null(image);
	image->img = mlx_new_image(data->mlx_ptr, width, height);
	if (image->img == NULL)
		clean_exit(data, FAILURE);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->size_line, &image->endian);
	return ;
}

/*initializes the MiniLibx library and creates
a new window for graphics display*/
void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		print_error("Mlx: Startup error");
		clean_exit(data, FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "Cub3D");
	if (!data->win_ptr)
	{
		print_error("Mlx: Window error");
		clean_exit(data, FAILURE);
	}
}
