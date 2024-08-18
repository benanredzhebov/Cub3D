/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map			map;
	t_data			data;

	data.map = &map;
	if (argc != 2)
	{
		fprintf(stderr, "PLEASE INSERT MAP FILE: %s <map_file.cub>\n", argv[0]);
		return (1);
	}
	read_map(argv[1], data.map);
	display_map(map, &data);
	return (0);
}
