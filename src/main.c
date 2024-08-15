/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/15 10:07:25 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_img	image; //delete it later
	
	if (argc != 2)
		return (print_error("Usage: ./cub3d <path/to/map.cub>"), 1);
	init_data(&data);
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	init_mlx(&data);
	init_textures(&data);
	init_img(&data, &image, data.map->win_width, data.map->win_height);
	// data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	// data.data_addr = mlx_get_data_addr
	// 	(data.img_ptr, &data.bpp, &data.size_line, &data.endian);
	// exit(0);
	// input(&data); remain this
	// mlx_hook(data.win_ptr, 2, 1L << 0, key_press, NULL);
	// mlx_key_hook(data.win_ptr, init_mlx_wrapper, (void *)0);
	
	// mlx_loop_hook(data.mlx_ptr, main_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}


int	init_mlx_wrapper(void *param)
{
	t_data *data = (t_data *)param;
	init_mlx(data);
	return (0);
}