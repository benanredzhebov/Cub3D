/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:32:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/08/05 12:28:32 by beredzhe         ###   ########.fr       */
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
