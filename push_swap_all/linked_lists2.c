/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:53:19 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/07 00:40:45 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	if (*lst)
	{
		last_element = ft_lstlast(*lst);
		last_element->next = new;
	}
	else
		*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*lst_p;
	t_list	*next;

	lst_p = *lst;
	while (lst_p != 0)
	{
		next = lst_p->next;
		ft_lstdelone(lst_p, del);
		lst_p = next;
	}
	*lst = 0;
}

void	free_stack(t_list **list)
{
	t_list	*next;

	while (*list)
	{
		next = (*list)->next;
		free(*list);
		(*list) = next;
	}
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_list;
	t_list	*new_el;

	if (!lst || !f)
		return (NULL);
	new_el = ft_lstnew(f(lst->content));
	if (!new_el)
		return (NULL);
	new_list = new_el;
	while (lst->next)
	{
		lst = lst->next;
		new_el = ft_lstnew(f(lst->content));
		if (!new_el)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_el);
	}
	return (new_list);
}
