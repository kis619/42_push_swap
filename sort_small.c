/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:35:51 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/02 13:35:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *stack)
{
	int	num;

	num = stack->content;
	while (stack)
	{
		if (stack->content < num)
			return (0);
		num = stack->content;
		stack = stack->next;
	}
	return (1);
}

int	top_is_smallest(t_list *stack)
{
	t_list	*top;

	top = stack;
	while (stack)
	{
		if ((stack)->content < top->content)
			return (0);
		stack = (stack)->next;
	}
	return (1);
}

int	mid_is_smallest(t_list *stack)
{
	int	first;
	int	second;
	int	third;
	int	fourth;
	int	fifth;

	first = (*stack).content;
	second = (*stack).next->content;
	third = (*stack).next->next->content;
	fourth = (*stack).next->next->next->content;
	fifth = (*stack).next->next->next->next->content;
	if (third < second && third < first && third < fourth && third < fifth)
		return (1);
	return (0);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (!sorted(*stack_a) && mid_is_smallest(*stack_a))
	{
		if ((*stack_a)->content != 5)
			ra(stack_a, 0);
	}
	while (!sorted(*stack_a))
	{
		if (top_is_smallest(*stack_a))
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 0);
		if (!top_is_smallest(*stack_a))
			rra(stack_a, 0);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_2_3_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;

	a = *stack_a;
	if (ft_lstsize(*stack_a) > 2 && (a->content > a->next->content
			&& (*stack_a)->content > (*stack_a)->next->next->content
			&& (*stack_a)->next->content < (*stack_a)->next->next->content))
		ra(stack_a, 0);
	while (!sorted(*stack_a))
	{
		if (top_is_smallest(*stack_a))
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 0);
		if (!top_is_smallest(*stack_a))
			rra(stack_a, 0);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
