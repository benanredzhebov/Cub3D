/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:29:23 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/19 08:56:15 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_pos_x + data->player_dir_x * MOVESPEED;
	new_y = data->player_pos_y + data->player_dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_pos_x - data->player_dir_x * MOVESPEED;
	new_y = data->player_pos_y - data->player_dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_pos_x + data->player_dir_y * MOVESPEED;
	new_y = data->player_pos_y - data->player_dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player_pos_x - data->player_dir_y * MOVESPEED;
	new_y = data->player_pos_y + data->player_dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player_move_y == 1)
		moved += move_player_forward(data);
	if (data->player_move_y == -1)
		moved += move_player_backward(data);
	if (data->player_move_x == -1)
		moved += move_player_left(data);
	if (data->player_move_x == 1)
		moved += move_player_right(data);
	if (data->player_rotate != 0)
		moved += rotate_player(data, data->player_rotate);
	return (moved);
}
