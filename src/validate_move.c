/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:45:38 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/19 08:54:04 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

static bool	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map->map_width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map->map_height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player_pos_y))
	{
		data->player_pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player_pos_x, new_y))
	{
		data->player_pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
