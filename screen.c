/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_square(void *mlx, void *win, int x, int y, int color)
{
	int i = 0;
	while (i < TILE_SIZE)
	{
		int j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(mlx, win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// void draw_textured_square(void *mlx, void *win, int x, int y, void *texture)
// {
// 	int i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		int j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			mlx_put_image_to_window(mlx, win, texture, x + i, y + j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int handle_key(int key, void *param)
{
	if (key == KEY_ESC)
		close_window(param);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S \
		|| key == KEY_LEFT || key == KEY_RIGHT)
		move_player(param, key);
	return (0);
}
void display_map(t_map map, t_data *data)
{
	// void *mlx;
	// void *win;
	int i;
	int j;
	int k;
	int color;

	data->map = &map;
	data->player.x = 0;
	data->player.y = 0;
	data->player.angle = EAST;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, map.width * TILE_SIZE, map.height * TILE_SIZE, "Cub3D");
	
	i = 0;
	k = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
// ft_printf("map.data[%d][%d] = %c\n", i, j, map.data[i][j]);
			if (map.map_data[i][j] == '1')
				color = create_trgb(0, 0, 10, 255); //0xFFFFFF
			else if (map.map_data[i][j] == 'E')
			{
// ft_printf("ENTROU EAST\n");
// ft_printf("player.x = %d, player.y = %d\n", j, i);
// ft_printf("1x = %d, y = %d, angle = %d\n", data->player.x, data->player.y, data->player.angle);
				data->player.x = j;
				data->player.y = i;
				data->player.angle = EAST;
// ft_printf("2x = %d, y = %d, angle = %d\n", data->player.x, data->player.y, data->player.angle);
			}
			else if (map.map_data[i][j] == 'N')
			{
// ft_printf("ENTROU NORTH\n");
				data->player.x = j;
				data->player.y = i;
				data->player.angle = NORTH;
			}
			else if (map.map_data[i][j] == 'W')
			{
// ft_printf("ENTROU WEST\n");
				data->player.x = j;
				data->player.y = i;
				data->player.angle = WEST;
			}
			else if (map.map_data[i][j] == 'S')
			{
// ft_printf("ENTROU SOUTH\n");
				data->player.x = j;
				data->player.y = i;
				data->player.angle = SOUTH;
			}
			else
			{
// ft_printf("ENTROU ELSE (0)\n");
				color = create_trgb(0, 255, 50, 255); //0x00FF00
			}
			draw_square(data->mlx, data->win, j * TILE_SIZE, i * TILE_SIZE, color);
			j++;
// ft_printf("X = %d, Y = %d, ANGLE = %d\n", data->player.x, data->player.y, data->player.angle);
		}
		i++;
	}
ft_printf("3x = %d, y = %d, angle = %d\n", data->player.x, data->player.y, data->player.angle);
	// color = create_trgb(0, 255, 255, 255);
	// draw_square(mlx, win, data->player.x * TILE_SIZE, data->player.y * TILE_SIZE, color);



	// color = create_trgb(0, 0, 0, 0);
	// mlx_pixel_put(data->mlx, data->win, data->player.x * TILE_SIZE + (TILE_SIZE/2), data->player.y * TILE_SIZE + (TILE_SIZE/2), color);
	// while (k < 10)
	// {
	// 	color = create_trgb(0, 255, 255, 0);
	// 	mlx_pixel_put(data->mlx, data->win,data->player.x * TILE_SIZE + (TILE_SIZE/2) + k + 2, \
	// 	data->player.y * TILE_SIZE + (TILE_SIZE/2) + k + 2, color);
	// 	k++;
	// }



	// mlx_pixel_put(mlx, win, map.width/2,  map.height/2, color);
	mlx_hook(data->win, 17, 0, close_window, data->mlx);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop(data->mlx);
}

int close_window(void *param)
{
	void **params = (void **)param;
	void *mlx = params[0];
	void *win = params[1];

	mlx_destroy_window(mlx, win);
	exit(0);
	return (0);
}
































// void display_map(char map[MAX_ROWS][MAX_COLS], int rows, int cols)
// {
// 	void *mlx;
// 	void *win;
// 	int i;
// 	int j;
// 	int color;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, cols * TILE_SIZE, rows * TILE_SIZE, "Cub3D");
// 	i = 0;
// 	while (i < rows)
// 	{
// 		j = 0;
// 		while (j < cols)
// 		{
// 			if (map[i][j] == '1')
// 				color = create_trgb (0, 0, 10, 255); //0xFFFFFF
// 			else
// 				color = create_trgb (0, 255, 50, 255); //0x00FF00
// 			draw_square(mlx, win, j * TILE_SIZE, i * TILE_SIZE, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_hook(win, 17, 0, close_window, mlx);
// 	mlx_key_hook(win, handle_key, mlx);
// 	mlx_loop(mlx);
// }

