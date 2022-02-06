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

void	calculate_b_rotation(t_list *stack_a, t_list *stack_b, int *r_a, int *r_b, int argc)
{
	
	
	int		max_dist = INT_MAX;
	int		i;
	int		total_dist;
	int		dist_b;
	int		dist_a;
	int		len_a;
	t_list	*temp;

	temp = stack_b;
	len_a = ft_lstsize(stack_a);
	i = 0;
	while (temp)
	{
		dist_b = distance_to_b(i++, argc - len_a);
		dist_a = distance_to_a(stack_a, temp->idx, len_a);
		total_dist = ft_abs(dist_a) + ft_abs(dist_b);
		if (dist_a > 0 && dist_b > 0)
			total_dist -= get_smaller_num(dist_a, dist_b);
		else if (dist_a < 0 && dist_b < 0)
			total_dist += get_bigger_num(dist_a, dist_b);
		if (total_dist < max_dist)
		{
			max_dist = total_dist;
			*r_a = dist_a;
			*r_b = dist_b;
		}
		temp = temp->next;
	}
}
