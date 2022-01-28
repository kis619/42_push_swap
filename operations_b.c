/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:58:11 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 16:08:16 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *stack_b)
{
	int	temp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
	write(1, "sb\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	ft_lstadd_front(stack_a, top_b);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
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
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
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
	write(1, "rrb\n", 4);
}
