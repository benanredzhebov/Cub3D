/* ************************************************************************** */
/*                                                                            */
/*   raytracer.h                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: demrodri <demrodri@student.42wolfsburg.de>   +:+ +:+         +:+     */
/*   beredzhe <beredzhe@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/02 17:12:40 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

# define WIDTH 800
# define HEIGHT 600
# define TILE_SIZE 64
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define M_PI 3.14159265358979323846

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_map	*map;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
}	t_player;

typedef struct s_render_data
{
	float	ray_angle;
	float	distance_to_wall;
	int		hit_wall;
	float	ray_pos_x;
	float	ray_pos_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
}	t_render_data;

typedef struct s_map
{
	int		width;
	int		height;
	char	*data;
}	t_map;

void		load_map(const char *filename);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			is_wall(int x, int y, t_map *map);
void		render(t_data *data, t_player *player, t_map *map);
int			key_press(int keycode, t_player *player, t_map *map);
int			main_loop(t_data *data);

#endif // RAYTRACER_H
