/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:28:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 16:06:54 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(*stack_a);
	sb(*stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
