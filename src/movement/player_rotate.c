/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:38:29 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/28 13:15:25 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

/*rotating a player's view and direction in a 2D plane for a
3D simulation*/
static int	rotate_left_right(t_data *data, double rotspeed)
{
	double	tmp_x;

	tmp_x = data->player_dir_x;
	data->player_dir_x = data->player_dir_x * cos(rotspeed)
		- data->player_dir_y * sin(rotspeed);
	data->player_dir_y
		= tmp_x * sin(rotspeed) + data->player_dir_y * cos(rotspeed);
	tmp_x = data->player_plane_x;
	data->player_plane_x = data->player_plane_x * cos(rotspeed)
		- data->player_plane_y * sin(rotspeed);
	data->player_plane_y
		= tmp_x * sin(rotspeed) + data->player_plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_data *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}
