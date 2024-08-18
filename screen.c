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

unsigned int get_pixel_color(t_data *data, int x, int y)
{
	int image_width;
	int image_height;

	if (data == NULL || data->addr == NULL)
	{
		fprintf(stderr, "Error: data or data->addr is NULL\n");
		return 0;
	}

	// Calculate the actual pixel dimensions
	image_width = data->map->width * TILE_SIZE;
	image_height = data->map->height * TILE_SIZE;

	// Ensure coordinates are within bounds
	if (x < 0 || x >= image_width || y < 0 || y >= image_height)
	{
		fprintf(stderr, "Error: Pixel coordinates out of bounds\n");
		return 0;
	}

	// Ensure line_length and bits_per_pixel are correctly set
	if (data->line_length <= 0 || data->bits_per_pixel <= 0)
	{
		fprintf(stderr, "Error: Invalid line_length or bits_per_pixel\n");
		return 0;
	}

	// Calculate the position of the pixel in the image data
	char *src = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return *(unsigned int*)src;
}

void put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = NULL;
	if (data == NULL || data->addr == NULL)
	{
		fprintf(stderr, "Error: data or data->addr is NULL\n");
		return;
	}

	// Debugging output
	// printf("Attempting to put pixel at (%d, %d) with color %d\n", x, y, color);
	// printf("Image dimensions: width = %d, height = %d\n", data->map->width , data->map->height);

	if (x < 0 || x >= data->map->width|| y < 0 || y >= data->map->height)
	{
		fprintf(stderr, "Error: Pixel coordinates out of bounds\n");
		return ;
	}

	// Ensure line_length and bits_per_pixel are correctly set
	if (data->line_length <= 0 || data->bits_per_pixel <= 0)
	{
		fprintf(stderr, "Error: Invalid line_length or bits_per_pixel\n");
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	// char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// *(unsigned int*)dst = color;
}
void draw_square(t_data *data, void *win, int x, int y, int color)
{
	// t_data *data_ptr;
	// data_ptr = data;

	int i = 0;
	while (i < TILE_SIZE)
	{
		int j = 0;
		while (j < TILE_SIZE)
		{
			// mlx_pixel_put(data->mlx, win, x + i, y + j, color);
			put_pixel_to_image(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, win, data->img, 0, 0);
}

void draw_lil_square(t_data *data, void *win, int x, int y, int color)
{
	int i = 0;
	while (i < PLAYER_SIZE)
	{
		int j = 0;
		while (j < PLAYER_SIZE)
		{	
			if (i == 0 && j == 0)
				mlx_pixel_put(data->mlx, win, x + i, y + j, BLACK);
			else
				mlx_pixel_put(data->mlx, win, x + i, y + j, color);
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
	data->img = mlx_new_image(data->mlx, data->map->width, data->map->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->win = mlx_new_window(data->mlx, map.width, map.height, "Cub3D");
	
	i = 0;
	k = 0;
	while (i < data->map->height / TILE_SIZE)
	{
		j = 0;
		while (j < data->map->width / TILE_SIZE)
		{
			if (map.map_data[i][j] == '1')
				color = WALL_CLR;
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
			data->player.x = j * TILE_SIZE;
			data->player.y = i * TILE_SIZE;
			color = FLOOR_CLR;
			}
			else
				color = FLOOR_CLR;

			draw_square(data, data->win, j * TILE_SIZE, i * TILE_SIZE, color);
			j++;
		}
		i++;
	}

	// draw_lil_square(data->mlx, data->win, data->player.x * TILE_SIZE + (TILE_SIZE/2), \
	// data->player.y * TILE_SIZE + (TILE_SIZE/2), WHITE);

	// mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y, BLACK);
	// 	mlx_pixel_put(data->mlx, data->win, data->player.x + 1, data->player.y, BLACK);
	// 		mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y + 1, BLACK);
	// 			mlx_pixel_put(data->mlx, data->win, data->player.x + 1, data->player.y + 1, BLACK);

	data->player.x = data->player.x  + (TILE_SIZE / 2);
	data->player.y = data->player.y  + (TILE_SIZE / 2);

	draw_lil_square(data->mlx, data->win, data->player.x - (PLAYER_SIZE / 2), data->player.y - (PLAYER_SIZE / 2), PLAYER_CLR);
	data->player.x = data->player.x - (PLAYER_SIZE / 2);
	data->player.y = data->player.y - (PLAYER_SIZE / 2);

	// mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y, WHITE);
	// 	mlx_pixel_put(data->mlx, data->win, data->player.x + 1, data->player.y, WHITE);
	// 		mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y + 1, WHITE);
	// 			mlx_pixel_put(data->mlx, data->win, data->player.x + 1, data->player.y + 1, WHITE);

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

