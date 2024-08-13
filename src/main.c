/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/10 12:56:45 by beredzhe         ###   ########.fr       */
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
	init_mlx(&data);
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.data_addr = mlx_get_data_addr
		(data.img_ptr, &data.bpp, &data.size_line, &data.endian);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_press, NULL);
	mlx_loop_hook(data.mlx_ptr, main_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}
