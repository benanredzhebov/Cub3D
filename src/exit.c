/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:32:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/20 11:10:53 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raytracer.h"

/*clean up resources and exit the program with a specified status*/
void	clean_exit(t_data *data, int exitstatus)
{
	if (data)
		free_data(data);
	exit(exitstatus);
}

int	quit_cub3d(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}
