/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:49:01 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 21:49:01 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **stack_a, t_list **stack_b, int *r_a, int *r_b)
{
	while (*r_a > 0 && *r_b > 0)
	{
		(*r_a)--;
		(*r_b)--;
		rr(stack_a, stack_b);
	}
	while (*r_a < 0 && *r_b < 0)
	{
		(*r_a)++;
		(*r_b)++;
		rrr(stack_a, stack_b);
	}
}

void	choose_rotation(t_list **stack_a, t_list **stack_b, int r_a, int r_b)
{
	rotate_both(stack_a, stack_b, &r_a, &r_b);
	while (r_a > 0)
	{
		r_a--;
		ra(stack_a, 0);
	}
	while (r_a < 0)
	{
		r_a++;
		rra(stack_a, 0);
	}
	while (r_b > 0)
	{
		r_b--;
		rb(stack_b, 0);
	}
	while (r_b < 0)
	{
		r_b++;
		rrb(stack_b, 0);
	}
}

void	calc_b_r(t_list *stack_a, t_list *stack_b, int r_a_b[2], int argc)
{
	t_list	*temp;
	t_dist	dist;

	dist.max_dist = INT_MAX;
	temp = stack_b;
	dist.len_a = ft_lstsize(stack_a);
	dist.i = 0;
	while (temp)
	{
		dist.b = distance_to_b(dist.i++, argc - dist.len_a);
		dist.a = distance_to_a(stack_a, temp->idx, dist.len_a);
		dist.total = ft_abs(dist.a) + ft_abs(dist.b);
		if (dist.a > 0 && dist.b > 0)
			dist.total -= small(dist.a, dist.b);
		else if (dist.a < 0 && dist.b < 0)
			dist.total += big(dist.a, dist.b);
		if (dist.total < dist.max_dist)
		{
			dist.max_dist = dist.total;
			r_a_b[0] = dist.a;
			r_a_b[1] = dist.b;
		}
		temp = temp->next;
	}
}
