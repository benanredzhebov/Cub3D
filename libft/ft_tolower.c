/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:39:51 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:51 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int alpha)
{
	if (alpha >= 'A' && alpha <= 'Z')
		alpha += 32;
	return (alpha);
}

/*conventing alphabets to upper using ascii values*/