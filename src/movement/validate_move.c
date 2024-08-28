/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:45:38 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/28 09:18:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

/*checks if a given (x,y) position is within the valid
bounds of the game map, ensuring it is not too close to the edges.
if (x < 0.25 || x >= data->map->map_width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map->map_height -0.25)
		return (false);
	return (true);*/
static bool is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0 || x >= data->map->map_width * TILE_SIZE)
		return (false);
	if (y < 0 || y >= data->map->map_height * TILE_SIZE)
		return (false);
	return (true);
}

static bool is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (true);
	return (false);
}

/*checks if the player can move to a new position on the map.
It updates the player's position if the move is valid.*/
int validate_move(t_data *data, double new_x, double new_y)
{
	int moved;

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
