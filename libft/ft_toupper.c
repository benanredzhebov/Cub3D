/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:39:58 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:39:59 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int alpha)
{
	if (alpha >= 'a' && alpha <= 'z')
		alpha -= 32;
	return (alpha);
}

/*conventing alphabets to upper using ascii values*/