/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:26:02 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/05 10:26:02 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_highest_num(t_list *stack)
{
	int		i;
	t_list	*biggest;

	biggest = NULL;
	i = stack->content;
	while (stack)
	{
		if (stack->content > i)
		{
			i = stack->content;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

void	ft_index(t_list *stack, int max_idx)
{
	t_list	*biggest;
	t_list	*first;
	int		i;

	first = stack;
	biggest = get_highest_num(stack);
	i = INT_MIN;
	while (-1 < max_idx)
	{
		printf("Max_idx = %d\n", max_idx);
		while (stack)
		{
			if (stack->idx == -1 && stack->content > i)
			{
				i = stack->content;
				biggest = stack;
			}
			stack = stack->next;
		}
		biggest->idx = max_idx;
		max_idx--;
		stack = first;
		i = INT_MIN;
	}
}

// int main (int argc, char *argv[])
// {
// 	t_list *stack;

// 	stack = get_initial_input(argv);
// 	ft_index(stack, argc - 2);
// 	print_list(stack);
// 	while (stack)
// 	{
// 		printf("%d ", (stack)->idx);
// 		(stack) = (stack)->next;
// 	}
// 	// printf("%d\n", biggest(stack)->content);
// 	// print_list(stack);
// }