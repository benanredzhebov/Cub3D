/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:34:15 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/05 13:17:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

int parsing(t_data *data, char **argv)
{
	char	**cub_file;
	
	if (validate_cub_file(argv[1]) == FAILURE)
		exit(FAILURE);
	save_cub(argv[1], data);
	cub_file = data->cub_file;
	if (retrieve_file_data(data, cub_file) == FAILURE)
		return (FAILURE);
}