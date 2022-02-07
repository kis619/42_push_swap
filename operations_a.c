/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:10:54 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/07 03:36:53 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack, int called)
{
	t_list	*temp;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return ;
	third = (*stack)->next->next;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = third;
	if (!called)
		print_func_name(__func__);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	ft_lstadd_front(stack_a, top_b);
	print_func_name(__func__);
}

void	ra(t_list **stack_a, int called)
{
	t_list	*top;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	top = *stack_a;
	(*stack_a) = (*stack_a)->next;
	last->next = top;
	top->next = NULL;
	if (!called)
		print_func_name(__func__);
}

void	rra(t_list **stack_a, int called)
{
	t_list	*last;
	t_list	*sec_last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	sec_last = ft_lstpenultimate(*stack_a);
	sec_last->next = NULL;
	last->next = *stack_a;
	(*stack_a) = last;
	if (!called)
		print_func_name(__func__);
}

void	pa_no_name(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	ft_lstadd_front(stack_a, top_b);
}