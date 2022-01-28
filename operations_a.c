/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:10:54 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 16:21:44 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *initial_element)
{
	int	second_cont;

	if (ft_lstsize(initial_element) < 2)
		return ;
	second_cont = initial_element->next->content;
	initial_element->next->content = initial_element->content;
	initial_element->content = second_cont;
	write(1, "sa\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	ft_lstadd_front(stack_b, top_a);
	write(1, "pa\n", 3);
}

void	ra(t_list **stack_a)
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
	write(1, "ra\n", 3);
}

void	rra(t_list **stack_a)
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
	write(1, "rra\n", 4);
}
