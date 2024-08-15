/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:07:44 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/15 22:06:22 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*initializes an image structure,
loads an XPM file into the image*/
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_null(image);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->tex_size,
			&data->tex_size);
	if (image->img == NULL)
	{
		print_error("Memory allocation failed");
		clean_exit(data, FAILURE);
	}
	/*retrieves the address and additional
	information about the image*/
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->size_line, &image->endian);
}

/*loads an XPM image, allocates a buffer to hold
the image data, copies the image data to the buffer,
destroysh the temporary image, and return the buffer*/
static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		r;
	int		c;
	
	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->tex_size * data->tex_size);
	if (!buffer)
		clean_exit(data, FAILURE);
	c = 0;
	while (c < data->tex_size)
	{
		r = 0;
		while (c <data->tex_size)
		{
			buffer[c * data->tex_size + r]
				= tmp.addr[c * data->tex_size + r];
			++r;
		}
		c++;
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img);
	return (buffer);
}

/*allocates memory for texture pointers, and
then loads the textures from specified XPM files
into the allocated array*/
void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof *data->textures);
	if (!data->textures)
		clean_exit(data, FAILURE);
	data->textures[NORTH] = xpm_to_img(data, data->tex_north);
	data->textures[SOUTH] = xpm_to_img(data, data->tex_south);
	data->textures[EAST] = xpm_to_img(data, data->tex_east);
	data->textures[WEST] = xpm_to_img(data, data->tex_west);
}
