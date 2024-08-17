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

void draw_lil_square(void *mlx, void *win, int x, int y, int color)
{
	int i = 0;
	while (i < PLAYER_SIZE)
	{
		int j = 0;
		while (j < PLAYER_SIZE)
		{
			mlx_pixel_put(mlx, win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

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
			if (map.map_data[i][j] == '1')
				color = CYAN;
			else if (map.map_data[i][j] == 'E' || map.map_data[i][j] == 'N' \
				|| map.map_data[i][j] == 'W' || map.map_data[i][j] == 'S')
			{
				if (map.map_data[i][j] == 'E')
					data->player.angle = EAST;
				else if (map.map_data[i][j] == 'N')
					data->player.angle = NORTH;
				else if (map.map_data[i][j] == 'W')
					data->player.angle = WEST;
				else if (map.map_data[i][j] == 'S')
					data->player.angle = SOUTH;
			data->player.x = j;
			data->player.y = i;
			}
			else
				color = MAGENTA;
			draw_square(data->mlx, data->win, j * TILE_SIZE, i * TILE_SIZE, color);
			j++;
		}
		i++;
	}

	draw_lil_square(data->mlx, data->win, data->player.x * TILE_SIZE + (TILE_SIZE/2), \
	data->player.y * TILE_SIZE + (TILE_SIZE/2), WHITE);

printf("1.data->player.x: %d data->player.y: %d\n", data->player.x, data->player.y);
	data->player.x = (data->player.x * TILE_SIZE) + (TILE_SIZE / 2);
	data->player.y = (data->player.y * TILE_SIZE) + (TILE_SIZE / 2);
	// draw_lil_square(data->mlx, data->win, data->player.x, data->player.y, BROWN);
printf("2.data->player.x: %d data->player.y: %d\n", data->player.x, data->player.y);

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

