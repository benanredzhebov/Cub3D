/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:55:00 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/27 13:13:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/raytracer.h"

void	init_img_null(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_data_cub_map(t_data *data)
{
	data->cub_path = NULL;
	data->cub_height = 0;
	data->cub_file = NULL;
	data->cub_fd = -42;
}

void	init_map(t_map *map)
{
	map->win_width = WIN_WIDTH;
	map->win_height = WIN_HEIGHT;
	map->map_height = 0;
	map->map_width = 0;
	map->map_end_index = 0;
	map->map_data = NULL;
}

void	init_data_player(t_data *data)
{
	data->player_dir = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_move_x = 0;
	data->player_move_y = 0;
	data->player_rotate = 0;
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->player_dir_x = 0;
	data->player_dir_y = 0;
	data->player_plane_x = 0;
	data->player_plane_y = 0;
	data->player_has_moved = 0;
}

void	init_data(t_data *data)
{
	init_data_cub_map(data);
	init_data_player(data);
	data->tex_east = NULL;
	data->tex_west = NULL;
	data->tex_north = NULL;
	data->tex_south = NULL;
	data->tex_size = TILE_SIZE;
	data->tex_x = 0;
	data->tex_y = 0;
	data->col_ceiling = NULL;
	data->col_floor = NULL;
	data->col_ceiling_int = 0;
	data->col_floor_int = 0;
	data->tex_pixels = NULL;
	data->textures = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}
