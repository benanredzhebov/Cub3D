/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/09 11:46:51 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

// -----------------LIBS---------------
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

//----------------MINILIBX-------------
# ifdef __LINUX__
#  include "../minilibx-linux/mlx.h"
# else
#  include "../minilibx_opengl_20191021/mlx.h"
# endif

//------------------LIBFT--------------
# include "../libft/libft.h"

//------------------DEBUG--------------
# define DEBUG 0

//------------KEYBOARD MACROS----------

# ifdef __LINUX__
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define X 33
# else
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define ESC 53
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define X 17
# endif

// -----------------------------------

# define WIDTH 800
# define HEIGHT 600
# define TILE_SIZE 64
// # define MAP_WIDTH 10
// # define MAP_HEIGHT 10
# define M_PI 3.14159265358979323846

enum e_status
{
	FAILURE = -42,
	SUCCESS = 0,
	TEXTURE_ADDED = 1
};

/* this struct is used only temporary to check validity of the map*/
typedef struct s_dfs
{
	char	**map;
	int		h;
	int		w;
	int		valid;
	int		dr[4];
	int		dc[4];
}	t_dfs;

typedef struct s_map
{
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
	int		map_end_index; // Index of the end of the map in the file
	char	**map_data;
}	t_map;


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_map	*map;
	char	*data_addr;
	char	player_dir; // Direction the player is facing (N, S, E, W)
	int		player_x; // Player's x-coordinate on the map
	int		player_y; // Player's y-coordinate on the map
	double	player_pos_x; // Player's exact x-position
	double	player_pos_y; // Player's exact y-position
	double	player_dir_x; // Player's direction vector x-component
	double	player_dir_y; // Player's direction vector y-component
	double	player_plane_x; // Player's camera plane x-component
	double	player_plane_y; // Player's camera plane y-component
	int		bpp;
	int		size_line;
	int		endian;
	int		**textures; //Array of textures
	int		**tex_pixels; //Array of texture pixels
	char	*tex_north; //Path to the north texture
	char	*tex_east; //Path to the east texture
	char	*tex_south; //Path to the south texture
	char	*tex_west; //Path to the west texture
	char	**cub_file; //Content of .cub file
	char	*cub_path; // Path to the .cub file
	int		cub_height; //Number of lines in the .cub file
	int		cub_fd; // File descriptor for the .cub file
	int		*col_ceiling; // RGB values for ceiling color
	int		*col_floor; // RGB values for floor color
	
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

//------------init.c--------------
void	init_data_player(t_data *data);
void	init_data_cub_map(t_data *data);
void	init_map(t_map *map);
void	init_data(t_data *data);

//------------utils.c--------------
void	print_error(char *error_msg);
bool	ft_isspace(char c);
bool	ft_isprint_no_space(int c);
size_t	find_max_width(t_data *data, int i);
size_t	ft_strlen_no_newline(const char *str);


//------------utils2.c------------
int	open_file(char *filepath, t_data *data);
char	*ft_strdup2(const char *s1, int len);

//------------debug.c-------------
void	print_array_2d_newline(char **array_2d);
void	print_array_2d(char **array_2d);

//------------parsing.c------------
int 	parsing(t_data *data, char **argv);

//---------validate_map.c----------
int		validate_map(t_data *data, char **map);

//---------add_player_dir.c--------
void	add_player_direction(t_data *data);

//----------add_colors.c----------
int		add_colors(t_data *data, char *line, int j);
int		col_only_digits(char **map);


//------------free.c---------------
void	free_array_2d(void **array_2d);
void	free_cub(t_data *data);
void	free_textures(t_data *data);
void	free_data(t_data *data);
void	free_colors(t_data *data);

//------------exit.c----------------
void	clean_exit(t_data *data, int exitstatus);

//------------save_cub.c------------
int		check_cub_file_extension(char *filename);
int		validate_cub_file(char *filename);
int		line_counter(char *filepath, t_data *data);
void	read_and_save_cub_file(int row, int col, int i, t_data *data);
void	save_cub(char *cub_path, t_data *data);

//------retrieve_file_data.c-------
int	retrieve_file_data(t_data *data, char **cub_file);

//----------add_map.c-------------
int		add_map(t_data *data, char **cub_file, int i);
int		no_tabs(t_data *data);

//----------add_map2.c-------------
void	make_map_rectangular(t_data *data);

//--------validate_walls.c---------
int		validate_walls(t_data *data);
int		is_last_char_one(const char *line);
int		dfs(t_data *data, char **map_clone);
void	dfs_recursive(t_dfs *map_data, int r, int c);
void	init_map_data(t_dfs *map_data, t_data *data, char **map_clone);

//---------------------------------

// void	load_map(const char *filename);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
// int		is_wall(int x, int y, int map[MAP_HEIGHT][MAP_WIDTH]);
// void	render(t_data *data, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH]);
int		key_press(int keycode, t_player *player, t_map *map);
int		main_loop(t_data *data);

#endif // RAYTRACER_H
