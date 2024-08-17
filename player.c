#include "cub3d.h"

void update_player(t_map map, t_data *data)
{
	int 	i;
	int 	j;
	int 	k;
	int 	color;
	// t_map 	mapa;

	// mapa = *data->map;

	mlx_clear_window(data->mlx, data->win); // Clear the window before redrawing


	i = 0;
	k = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map_data[i][j] == '1')
				color = create_trgb(0, 0, 10, 255); //0xFFFFFF
			else
			{
				color = create_trgb(0, 255, 50, 255); //0x00FF00
			}
			draw_square(data->mlx, data->win, j * TILE_SIZE, i * TILE_SIZE, color);
			j++;
		}
		i++;
	}
ft_printf("4x = %d, y = %d, angle = %d\n", data->player.x, data->player.y, data->player.angle);






	color = create_trgb(0, 0, 0, 0);
	mlx_pixel_put(data->mlx, data->win, data->player.x * TILE_SIZE + (TILE_SIZE/2), data->player.y * TILE_SIZE + (TILE_SIZE/2), color);
	while (k < 10)
	{
		color = create_trgb(0, 255, 255, 0);
		mlx_pixel_put(data->mlx, data->win,data->player.x * TILE_SIZE + (TILE_SIZE/2) + k + 2, \
		data->player.y * TILE_SIZE + (TILE_SIZE/2) + k + 2, color);
		k++;
	}
}

void move_player(t_data *data, int key)
{
	t_map	map;

	map = *data->map;
	if (key == KEY_W)
	{
		data->player.y -= 1;
		printf("W: %d %d %d\n", data->player.x, data->player.y, data->player.angle);
	}
	else if (key == KEY_A)
	{
		data->player.x -= 1;
		printf("A: %d %d %d\n", data->player.x, data->player.y, data->player.angle);
	}
	else if (key == KEY_S)
	{
		data->player.y += 1;
		printf("S: %d %d %d\n", data->player.x, data->player.y, data->player.angle);
	}
	else if (key == KEY_D)
	{
		data->player.x += 1;
		printf("D: %d %d %d\n", data->player.x, data->player.y, data->player.angle);
	}
	else if (key == KEY_LEFT)
	{
		data->player.angle -= 15; // Rotate left by 15 degrees
		if (data->player.angle < 0)
			data->player.angle += 360;
		printf("L: %d %d %d\n", data->player.x, data->player.y, data->player.angle);
	}
	else if (key == KEY_RIGHT)
	{
		data->player.angle += 15; // Rotate right by 15 degrees
		if (data->player.angle >= 360)
			data->player.angle -= 360;
		printf("R: %d %d %d\n", data->player.x, data->player.y, data->player.angle);
	}
	update_player(map, data);
}


















// int handle_key_press(int key, t_data *data)
// {
//     move_player(data, key);
//     display_map(data->map, data); // Redraw the map with the updated player position and angle
//     return (0);
// }


// void	move_player(t_player *player, float move_speed, int direction, t_map *map)
// {
//     float	new_x = player->x + cos(player->angle) * move_speed * direction;
//     float	new_y = player->y + sin(player->angle) * move_speed * direction;

//     if (!is_wall(new_x, new_y, map))
//     {
//         player->x = new_x;
//         player->y = new_y;
//     }
// }

// void	rotate_player(t_player *player, float rot_speed, int direction)
// {
//     player->angle += rot_speed * direction;
// }

// int	key_press(int keycode, t_data *data)
// {
//     float	move_speed = 0.1;
//     float	rot_speed = 0.05;

//     if (keycode == 13) // W key
//         move_player(data->player, move_speed, 1, data->map);
//     else if (keycode == 1) // S key
//         move_player(data->player, move_speed, -1, data->map);
//     else if (keycode == 0) // A key
//         rotate_player(data->player, rot_speed, -1);
//     else if (keycode == 2) // D key
//         rotate_player(data->player, rot_speed, 1);
//     return (0);
// }

// int	main_loop(t_data *data)
// {
//     mlx_clear_window(data->mlx_ptr, data->win_ptr);
//     render(data, data->player, data->map);
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
//     return (0);
// }