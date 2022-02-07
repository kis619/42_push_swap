/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:28:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/07 04:07:37 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	print_func_name(__func__);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	print_func_name(__func__);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	print_func_name(__func__);
}

void	operation_no_name(t_list **stack_a, t_list **stack_b, char trigger)
{
	if (trigger == 's')
	{
		sa(stack_a, 1);
		sb(stack_b, 1);
	}
	else if (trigger == 'r')
	{
		ra(stack_a, 1);
		rb(stack_b, 1);
	}
	else
	{
		rra(stack_a, 1);
		rrb(stack_b, 1);
	}
}
