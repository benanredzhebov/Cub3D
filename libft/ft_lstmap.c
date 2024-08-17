/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:36:44 by demrodri          #+#    #+#             */
/*   Updated: 2024/02/22 00:36:45 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&new_list, new_node);
			lst = lst->next;
		}
	}
	return (new_list);
}

/*
the code checks if the function application was successful
that is (new_list != NULL) and if there are more nodes in
the list (lst->next != NULL). If both conditions are met,
it recursively calls ft_lstmap on the next node of the
original list (lst->next).
*/