/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:05:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 17:55:14 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creates a new node
t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != 0)
		new->next = *lst;
	*lst = new;
}

//returns number of elements in list
int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

//returns the last node
t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//returns the penultimate node
t_list	*ft_lstpenultimate(t_list *lst)
{
	t_list	*second_to_last;

	while (lst->next != NULL)
	{
		second_to_last = lst;
		lst = lst->next;
	}
	return (second_to_last);
}
