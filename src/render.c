/* ************************************************************************** */
/*                                                                            */
/*   render.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: demrodri <demrodri@student.42wolfsburg.de>   +:+ +:+         +:+     */
/*   beredzhe <beredzhe@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/02 17:12:40 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*sets the pixel color of an image based on texture pixel value.
Setting image pixel to ceiling color.
Setting image pixel to floor color.
printf("Debug: x = %d, y = %d\n", x, y);
printf("Debug: tex_pixel = %d\n", data->tex_pixels[y][x]);
printf("Debug: win_height = %d\n", data->map->win_height);
printf("Debug: col_ceiling_int = %d, col_floor_int = %d\n",
data->col_ceiling_int, data->col_floor_int);*/
static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->tex_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->tex_pixels[y][x]);
	else if (y < data->map->win_height / 2)
		set_image_pixel(image, x, y, data->col_ceiling_int);
	else if (y < data->map->win_height - 1 && y >= WIN_HEIGHT / 2)
		set_image_pixel(image, x, y, data->col_floor_int);
}

/*iterates over each pixel to set its color,displays the image in the window
(mlx_put_image_to_window)*/
static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->map->win_width, data->map->win_height);
	y = 0;
	while (y < data->map->win_height)
	{
		x = 0;
		while (x < data->map->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image.img);
}

void	render_images(t_data *data)
{
	init_texture_pixels(data);
	// raycasting(data);
	render_frame(data);
}

/*updates the player's position and checks if the player
has moved.
If the player has not moved, it returns immediately.
if the player has moved, it calls render_images to 
update the game display.*/
int	render(t_data *data)
{
	data->player_has_moved += move_player(data);
	if (data->player_has_moved == 0)
		return (0);
	render_images(data);
	return (0);
}
