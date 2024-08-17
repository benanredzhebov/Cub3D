/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:36:30 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:36:30 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
we are iterating over each node in the linked
list and applying the function f to the content
of each node. the loop continues as long as lst is not null.
Inside the loop, f is called and passed the content of the
current node, lst->content. the provided function f to the
content of each node in the linked list.
*/