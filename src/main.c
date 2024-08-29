/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/29 10:01:15 by beredzhe         ###   ########.fr       */
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
	init_textures(&data);
	render_images(&data);
	get_input(&data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}
