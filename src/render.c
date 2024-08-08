/* ************************************************************************** */
/*                                                                            */
/*   render.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: demrodri <demrodri@student.42wolfsburg.de>   +:+ +:+         +:+     */
/*   beredzhe <beredzhe@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:11:39 by both              #+#    #+#             */
/*   Updated: 2024/08/02 17:12:40 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/raytracer.h"

// void	init_render_data(t_render_data *render_data, t_player *player)
// {
// 	render_data->ray_angle = 0.0;
// 	render_data->distance_to_wall = 0.0;
// 	render_data->hit_wall = 0;
// 	render_data->ray_pos_x = player->x;
// 	render_data->ray_pos_y = player->y;
// }

// void	cast_ray(t_render_data *render_data, \
// 		t_player *player, int x, int map[MAP_HEIGHT][MAP_WIDTH])
// {
// 	render_data->ray_angle = (player->angle - M_PI / 6.0) \
// 		+ ((float)x / WIDTH) * (M_PI / 3.0);
// 	render_data->distance_to_wall = 0.0;
// 	render_data->hit_wall = 0;
// 	printf("Ray %d: Angle %f\n", x, render_data->ray_angle);
// 	while (!render_data->hit_wall && render_data->distance_to_wall < 20.0)
// 	{
// 		render_data->ray_pos_x += cos(render_data->ray_angle) * 0.1;
// 		render_data->ray_pos_y += sin(render_data->ray_angle) * 0.1;
// 		render_data->distance_to_wall += 0.1;
// 		if (is_wall((int)render_data->ray_pos_x, \
// 			(int)render_data->ray_pos_y, map))
// 			render_data->hit_wall = 1;
// 	}
// 	printf("Ray %d: Angle %f, Distance %f\n", \
// 		x, render_data->ray_angle, render_data->distance_to_wall);
// 	if (render_data->distance_to_wall >= 20.0)
// 		render_data->distance_to_wall = 20.0;
// }

// void	draw_column(t_data *data, t_render_data *render_data, int x)
// {
// 	int	y;

// 	render_data->line_height = (int)(HEIGHT / render_data->distance_to_wall);
// 	render_data->draw_start = -render_data->line_height / 2 + HEIGHT / 2;
// 	render_data->draw_end = render_data->line_height / 2 + HEIGHT / 2;
// 	if (render_data->draw_start < 0)
// 		render_data->draw_start = 0;
// 	if (render_data->draw_end >= HEIGHT)
// 		render_data->draw_end = HEIGHT - 1;
// 	render_data->color = create_trgb(0, 255 / (render_data->distance_to_wall \
// 			+ 1), 255 / (render_data->distance_to_wall + 1), \
// 					255 / (render_data->distance_to_wall + 1));
// 	y = render_data->draw_start;
// 	while (y < render_data->draw_end)
// 	{
// 		my_mlx_pixel_put(data, x, y, render_data->color);
// 		++y;
// 	}
// }

// void	render(t_data *data, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH])
// {
// 	t_render_data	render_data;
// 	int				x;

// 	init_render_data(&render_data, player);
// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		cast_ray(&render_data, player, x, map);
// 		draw_column(data, &render_data, x);
// 		++x;
// 	}
// }