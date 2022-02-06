/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:30:39 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 21:57:29 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Input: list of strings.
	Applies atoi to the elements, makes nodes and links them in a Linked list.
*/
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

/* 
	prints the content of all nodes
*/
void	print_list(t_list *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->content);
		node = node->next;
	}
	printf("\n");
}

void print_func_name(const char *str)
{
	write(1, ft_strjoin(str, "\n"), ft_strlen(str) + 1);
}

int curr_prox_is_smaller(int n1, int n2)
{
	return (ft_abs(n1) < ft_abs(n2));
}