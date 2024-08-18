/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map			map;
	t_data			data;

	data.map = &map;
	if (argc != 2)
	{
		fprintf(stderr, "PLEASE INSERT MAP FILE: %s <map_file.cub>\n", argv[0]);
		return (1);
	}
	read_map(argv[1], data.map);
// printf("READ MAP\n");
	display_map(map, &data);
	return (0);
}


























// int	main(int argc, char *argv[])
// {
// 	// t_map			map;
// 	// t_render_data	render_data;

// 	if (argc != 2)
// 	{
// 		fprintf(stderr, "PLEASE INSERT MAP FILE: %s <map_file.cub>\n", argv[0]);
// 		return (1);
// 	}

// 	char map[MAX_ROWS][MAX_COLS];
// 	// read_map(argv[1], map);
// 	int rows, cols;
// 	read_map(argv[1], map, &rows, &cols);

// 	// for (int i = 0; i < MAX_ROWS; i++)
// 	// 	printf("%s\n", map[i]);

// 	// load_map(argv[1], &map);

// 	// init_render_data(&render_data, "Map Viewer");
// 	// render_map(&render_data, &map);
// 	// mlx_put_image_to_window(render_data.mlx, render_data.win, render_data.img, 0, 0);
// 	// mlx_loop(render_data.mlx);

// 	// cleanup(&render_data);
// 	// free_map(&map);

// 	return (0);
// }