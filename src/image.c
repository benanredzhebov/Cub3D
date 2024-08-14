/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:14:38 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/14 12:33:57 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_null(image);
	image->img = mlx_new_image(data->mlx_ptr, width, height);
	if (image->img == NULL)
		clean_exit(data, FAILURE);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}
