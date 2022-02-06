/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:54:09 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 08:54:09 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	distance_to_b(int idx, int size)
{
	if (idx >= size / 2)
		idx -= size;
	return (idx);
}

int distance_to_a(t_list *stack_a, int idx, int size)
{
	t_list *temp;
	t_list *last;
	int curr_and_min[2];
	int i;

	i = 0;
	temp = stack_a;
	last = ft_lstlast(stack_a);
	curr_and_min[1] = INT_MIN;
	while (temp)
	{
		if ((last->idx > temp->idx && (idx < temp->idx || idx > last->idx))
			|| (idx < temp->idx && idx > last->idx))
		{
			curr_and_min[0] = i;
			if (curr_and_min[0] > size / 2)
				curr_and_min[0] -= size;
			if (ft_abs(curr_and_min[0]) < curr_and_min[1])
				curr_and_min[1] = curr_and_min[0];
		}
		last = temp;
		temp = temp->next;
		i++;
	}
	return (curr_and_min[1]);
}


void calculate_b_rotation(t_list *stack_a, t_list *stack_b, int *r_a, int *r_b, int argc)
{
	int max_dist = INT_MAX;
	int i;
	int total_dist;
	int dist_b;
	int dist_a;
	int len_a;

	t_list *temp;
	temp = stack_b;
	len_a = ft_lstsize(stack_a);
	len_a = 
	i = 0;

	while (temp)
	{
		dist_b = distance_to_b(i++, argc - len_a);
		dist_a = distance_to_a(stack_a, temp->idx, len_a);
		total_dist = ft_abs(dist_a) + ft_abs(dist_b);
		if (dist_a > 0 && dist_b > 0)
			total_dist -= !get_bigger_num(dist_a, dist_b);
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

void initialise_b(t_list **stack_a, t_list **stack_b, int size, int argc)
{
	int r_a;
	int r_b;

	while (*stack_b)
	{
		calculate_b_rotation(*stack_a, *stack_b, &r_a, &r_b, argc);
		choose_rotation(stack_a, stack_b, r_a, r_b);
		pa(stack_a, stack_b);
		size++;
	}
	choose_rotation(stack_a, stack_b, distance_to_top(*stack_a, 0), 0);
}