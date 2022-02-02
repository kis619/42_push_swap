/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:58:11 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/02 13:31:34 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *stack_b, int called)
{
	int	temp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
	if (!called)
		print_func_name(__func__);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	
	if (ft_lstsize(*stack_a) < 1)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	ft_lstadd_front(stack_b, top_a);
	print_func_name(__func__);
}

void	rb(t_list **stack_b, int called)
{
	t_list	*top;
	t_list	*last;
	t_list	*second;


	if (ft_lstsize(*stack_b) < 2)
		return ;
	top = *stack_b;
	second = top->next;
	last = ft_lstlast(*stack_b);
	(*stack_b) = second;
	top->next = NULL;
	last->next = top;
	if (!called)
		print_func_name(__func__);
}



void	rrb(t_list **stack_b, int called)
{
	t_list	*last;
	t_list	*penultimate;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	last = ft_lstlast(*stack_b);
	penultimate = ft_lstpenultimate(*stack_b);
	last->next = *stack_b;
	(*stack_b) = last;
	penultimate->next = NULL;
	if (!called)
		print_func_name(__func__);
}
