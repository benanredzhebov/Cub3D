#include "cub3d.h"

void update_player(t_data *data, int new_x, int new_y, int new_angle)
{
	// Clear the previous player position
	draw_lil_square(data->mlx, data->win, data->player.x, data->player.y, MAGENTA);
	mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y, MAGENTA);

	// Update the player's position
	data->player.x = new_x;
	data->player.y = new_y;
	data->player.angle = new_angle;

	// Draw the player at the new position
	draw_lil_square(data->mlx, data->win, data->player.x, data->player.y, WHITE);
}

int is_wall(int x, int y, t_data *data)
{
	if (get_pixel_color(data, x, y) == CYAN)
		return (1);
	else if (get_pixel_color(data, x , y) == CYAN)
		return (1);
	else
		return (0);
	// mlx_pixel_put(data->mlx, data->win, x, y, BLACK);
    // unsigned int color = get_pixel_color(data, x, y);
    // printf("Color of pixel at (%d, %d): %u\n", x, y, color);
	// if (color == CYAN)
	// 	return (1);
	// else 
	// 	return (0);
}





// int	is_wall(int x, int y, t_map *map)
// {
// printf("x: %d y: %d map-width: %d map-height: %d map-data: %c\n", x, y, map->width, map->height, map->map_data[y][x]);
// 	if (x < 0 || x > map->width || y < 0 || y >= map->height)
// 		return (1);
// 	if (map->map_data[y][x] == '1')
// 		return (1);
// 	return (0);
// }

void move_player(t_data *data, int key)
{
	t_map	map;
	int		new_x;
	int		new_y;
	int		new_angle;

	map = *data->map;
	new_x = data->player.x;
	new_y = data->player.y;
	new_angle = data->player.angle;

printf("3.data->player.x: %d data->player.y: %d\n", data->player.x, data->player.y);

	if (key == KEY_W)
	{
		if (!is_wall(data->player.x, data->player.y - (6 + SPEED), data))
		{			
		printf("1.W: %d %d %d\n", new_x, new_y, new_angle);
			new_y = data->player.y - (PLAYER_SIZE + SPEED);
		}
		printf("2.W: %d %d %d\n", new_x, new_y, new_angle);
	}
	else if (key == KEY_A)
	{
		if (!is_wall(data->player.x - 6, data->player.y, data))
		{
			new_x = data->player.x - PLAYER_SIZE;
		}
		printf("A: %d %d %d\n", new_x, new_y, new_angle);
	}
	else if (key == KEY_S)
	{
		if (!is_wall(data->player.x, data->player.y + PLAYER_SIZE + 5, data))
		{
			new_y = data->player.y + PLAYER_SIZE;
		}
		printf("S: %d %d %d\n", new_x, new_y, new_angle);
	}
	else if (key == KEY_D)
	{
		if (!is_wall(data->player.x + PLAYER_SIZE + 5, data->player.y, data))
		{
			new_x = data->player.x + PLAYER_SIZE;
		}
		printf("S: %d %d %d\n", new_x, new_y, new_angle);
	}
	// else if (key == KEY_LEFT)
	// {
	// 	// data->player.angle -= 15; // Rotate left by 15 degrees
	// 	// if (data->player.angle < 0)
	// 	// 	data->player.angle += 360;
	// 	new_x = data->player.x;
	// 	new_y = data->player.y;
	// 	new_angle = data->player.angle - 15; // Rotate left by 15 degrees
	// 	if (new_angle < 0)
	// 		new_angle += 360;

	// 	printf("L: %d %d %d\n", new_x, new_y, new_angle);
	// }
	// else if (key == KEY_RIGHT)
	// {
	// 	// data->player.angle += 15; // Rotate right by 15 degrees
	// 	// if (data->player.angle >= 360)
	// 	// 	data->player.angle -= 360;

	// 	new_angle = data->player.angle + 15; // Rotate right by 15 degrees
	// 	if (new_angle >= 360)
	// 		new_angle -= 360;

	// 	printf("R: %d %d %d\n", new_x, new_y, new_angle);
	// }
	update_player(data, new_x, new_y, new_angle);
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

// void update_player(t_map map, t_data *data)
// {
// 	// int 	i;
// 	// int 	j;
// 	int 	k;
// 	int 	color;
// 	t_map 	mapa;

// 	mapa = map;

// 	mlx_clear_window(data->mlx, data->win); // Clear the window before redrawing
	


// 	// i = 0;
// 	k = 0;
// 	// while (i < map.height)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < map.width)
// 	// 	{
// 	// 		if (map.map_data[i][j] == '1')
// 	// 			color = create_trgb(0, 0, 10, 255); //0xFFFFFF
// 	// 		else
// 	// 		{
// 	// 			color = create_trgb(0, 255, 50, 255); //0x00FF00
// 	// 		}
// 	// 		draw_square(data->mlx, data->win, j * TILE_SIZE, i * TILE_SIZE, color);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// ft_printf("4x = %d, y = %d, angle = %d\n", data->player.x, data->player.y, data->player.angle);


// 	color = create_trgb(0, 0, 0, 0);
// 	mlx_pixel_put(data->mlx, data->win, data->player.x * TILE_SIZE + (TILE_SIZE/2), data->player.y * TILE_SIZE + (TILE_SIZE/2), color);

// 	while (k < 10)
// 	{
// 		color = create_trgb(0, 255, 255, 0);
// 		mlx_pixel_put(data->mlx, data->win,data->player.x * TILE_SIZE + (TILE_SIZE/2) + k + 2, \
// 		data->player.y * TILE_SIZE + (TILE_SIZE/2) + k + 2, color);
// 		k++;
// 	}
// }