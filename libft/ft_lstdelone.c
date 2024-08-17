/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:36:22 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:36:23 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}

/*
ft_lstdelone is to delete a single node
from a linked list while properly freeing
the memory associated with that node's content.
*/