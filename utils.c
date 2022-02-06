/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:30:39 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 23:35:53 by kmilchev         ###   ########.fr       */
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

void	print_func_name(const char *str)
{
	char	*word;

	word = ft_strjoin(str, "\n");
	write(1, word, ft_strlen(str) + 1);
	free(word);
}

int	curr_prox_is_smaller(int n1, int n2)
{
	return (ft_abs(n1) < ft_abs(n2));
}

int	time_to_swap(t_list *stack)
{
	t_list	first;
	t_list	second;

	first.next = &second;
	first.idx = stack->next->idx;
	second.next = stack->next->next;
	second.idx = stack->idx;
	if (len_biggest_loop(stack, 0) < len_biggest_loop(&first, 0))
		return (1);
	return (0);
}

t_data	fill_data(t_list **stack_a)
{
	t_data	data;

	data.stack_size = ft_lstsize(*stack_a);
	len_biggest_loop(*stack_a, 1);
	data.groups = big(1, data.stack_size / 150);
	data.group_size = data.stack_size / data.groups;
	data.cur_group = 1;
	data.r_b = 0;
	return (data);
}

// /* 
// 	prints the content of all nodes
// */
// void	print_list(t_list *node)
// {
// 	while (node != NULL)
// 	{
// 		printf(" %d ", node->content);
// 		node = node->next;
// 	}
// 	printf("\n");
// }
