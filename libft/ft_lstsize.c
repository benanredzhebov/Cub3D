/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:36:58 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:36:59 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

/*
ft_lstsize is to count the numb of nodes
in a linked list. It takes the starting 
node of the list as the parameter lst and
iterates through the list, counting each
node it encounters. It keeps track of the
count using the len variable.
*/