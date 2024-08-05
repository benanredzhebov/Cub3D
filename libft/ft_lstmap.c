/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:56:01 by beredzhe          #+#    #+#             */
/*   Updated: 2023/11/28 18:12:39 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	*func(int *ptr)
// {
// 	return (ptr);
// }

// void	delete(t_list *node)
// {
// 	free(node);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (0);
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (save);
}

// int main()
// {
// 	t_list *head;
// 	int ptr = 5;

// 	head = ft_lstnew(&ptr);
// 	head->next = ft_lstnew(&ptr);
// 	head->next->next = ft_lstnew(&ptr);

// 	t_list *head2 = ft_lstmap(head, func, delete);
// 	printf("%i\n", head2->content);
// }
