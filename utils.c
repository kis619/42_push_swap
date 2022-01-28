/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:30:39 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 17:51:47 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_initial_input(char *argv[])
{
	int		i;
	t_list	*new_el;
	t_list	*new_list;

	new_list = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		new_el = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&new_list, new_el);
		i++;
	}
	return (new_list);
}

void	print_list(t_list *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->content);
		node = node->next;
	}
}
