/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/10 11:41:15 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error("Usage: ./cub3d <path/to/map.cub>"), 1);
	init_data(&data);
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		print_error("Memmory allocation failed");
		clean_exit(&data, FAILURE);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Raycasting");
	if (!data.win_ptr)
	{
		print_error("Mlx: Window error");
		clean_exit(&data, FAILURE);
	}
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.data_addr = mlx_get_data_addr
		(data.img_ptr, &data.bpp, &data.size_line, &data.endian);
	return (free_data(&data), SUCCESS);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_press, NULL);
	mlx_loop_hook(data.mlx_ptr, main_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}
