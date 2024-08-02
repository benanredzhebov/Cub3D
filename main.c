/* ************************************************************************** */
/*                                                                            */
/*   raytracer.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: demrodri <demrodri@student.42wolfsburg.de>   +:+ +:+         +:+     */
/*   beredzhe <beredzhe@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/02 17:12:40 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <mapfile>\n", argv[0]);
		return (1);
	}
	load_map(argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Raycasting");
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.data_addr = mlx_get_data_addr 
		(data.img_ptr, &data.bpp, &data.size_line, &data.endian);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_press, NULL);
	mlx_loop_hook(data.mlx_ptr, main_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
