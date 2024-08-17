/* ************************************************************************** */
/*                                                                            */
/*                      f                                  :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demacinema <demacinema@student.42.de>      +#+  +:+       +#+        */
/*   beredzhe <beredzhe@student.42wolfsburg.de>   +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:18 by both              #+#    #+#             */
/*   Updated: 2024/08/12 15:25:55 by both             ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

