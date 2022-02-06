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

int	distance_to_a(t_list *stack_a, int idx, int size)
{
	t_list	*temp;
	t_list	*last;
	int		curr_and_min[2];
	int		i;

	i = 0;
	temp = stack_a;
	last = ft_lstlast(stack_a);
	curr_and_min[1] = INT_MAX;
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

void	initialise_b(t_list **stack_a, t_list **stack_b, int argc)
{
	int	r_a_b[2];

	while (*stack_b)
	{
		calc_b_r(*stack_a, *stack_b, r_a_b, argc);
		choose_rotation(stack_a, stack_b, r_a_b[0], r_a_b[1]);
		pa(stack_a, stack_b);
	}
	choose_rotation(stack_a, stack_b, distance_to_top(*stack_a, 0), 0);
}
