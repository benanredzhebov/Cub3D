/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/05 10:21:48 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

void	move_player(t_player *player, \
			float move_speed, int direction, t_map *map)
{
	float	new_x;
	float	new_y;

	new_x = player->x + cos(player->angle) * move_speed * direction;
	new_y = player->y + sin(player->angle) * move_speed * direction;
	if (!is_wall(new_x, new_y, map))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	rotate_player(t_player *player, float rot_speed, int direction)
{
	player->angle += rot_speed * direction;
}

int	key_press(int keycode, t_player *player, t_map *map)
{
	float	move_speed;
	float	rot_speed;

	move_speed = 10.0;
	rot_speed = 0.1;

	if (keycode == 13) // W
		move_player(player, move_speed, 1, map);
	else if (keycode == 1) // S
		move_player(player, move_speed, -1, map);
	else if (keycode == 0) // A
		rotate_player(player, rot_speed, -1);
	else if (keycode == 2) // D
		rotate_player(player, rot_speed, 1);
	else if (keycode == 53) // Esc
		exit(0);
	return (0);
}

int	main_loop(t_data *data)
{
	static t_player	player = {TILE_SIZE * 1.5, TILE_SIZE * 1.5, 0};

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render(data, &player, data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
