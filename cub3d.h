/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./libft/ft_printf/ft_printf.h"
#include "./libft/gnl/get_next_line.h"
#include "./libft/libft.h"

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

# include <string.h>

# define WIDTH 800
# define HEIGHT 600
# define TILE_SIZE 64
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
#define MAX_ROWS 100
#define MAX_COLS MAX_ROWS + 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define MOVE_SPEED 0.1
#define ROT_SPEED 0.05
#define NORTH 0
#define EAST 45
#define SOUTH 90
#define WEST 135
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_ESC 53

typedef struct s_game
{
	float px, py, pa; // Player position and angle
	float pdx, pdy;  // Player direction
	void *mlx_ptr;    // MiniLibX pointer
	void *win_ptr;    // Window pointer
	int *map;
} t_game;

typedef struct s_player
{
	int		x;
	int		y;
	int		angle;
}	t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map_data;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		*map;
	// void	*img_ptr;
	// char	*data_addr;
	// int		bpp;
	// int		size_line;
	// int		endian;
}	t_data;

typedef struct s_ray_data
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
}	t_ray_data;

typedef struct s_render_data
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_render_data;

// cub3d_utils.c
int	create_trgb(int t, int r, int g, int b);

//map.c
void read_map(const char *filename, t_map *map);
// void read_map(const char *filename, char map[MAX_ROWS][MAX_COLS],int *rows, int *cols);

//screen.c
void draw_square(void *mlx, void *win, int x, int y, int color);
// void display_map(t_map map);
void display_map(t_map map, t_data *data);
// void display_map(char map[MAX_ROWS][MAX_COLS], int rows, int cols);
int close_window(void *param);

//raycharles.c
// int	is_wall(int x, int y, t_map *map);

//player.
int	handle_key(int keycode, void *param);
// int handle_key_press(int key, t_data *data);
void move_player(t_data *data, int key);
// void move_player(t_player *player, float move_speed, int direction, char **map);
// void rotate_player(t_player *player, float rot_speed, int direction);
// int key_press(int keycode, t_data *data);
// void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1);
// void render_player(t_data *data);
// int main_loop(t_data *data);

#endif // CUB3D_H
