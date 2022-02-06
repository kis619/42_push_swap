/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:45:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 21:45:37 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **s_a, t_list **s_b, t_data data, int argc)
{
	t_list	*temp;

	while (data.cur_group <= data.groups + 1)
	{
		temp = closest_to_top(*s_a, data.cur_group, data.group_size);
		if (temp == NULL && data.cur_group++)
			continue ;
		data.d_top = distance_to_top(*s_a, temp->idx);
		if (time_to_swap(*s_a))
		{
			sa(s_a, 0);
			len_biggest_loop(*s_a, 1);
		}
		else if (!(*s_a)->marked && data.d_top == 0)
		{
			pb(s_a, s_b);
			data.stack_size--;
		}
		else if (data.cur_group == 1)
			rr(s_a, s_b);
		else
			choose_rotation(s_a, s_b, small(1, big(-1, data.d_top)), data.r_b);
	}
	initialise_b(s_a, s_b, argc);
}

int	find_loops(t_list *list, t_list *start, int set)
{
	t_list	*temp;
	int		max;
	int		counter;

	max = -1;
	counter = 0;
	temp = start;
	while (temp)
	{
		if (set)
			temp->marked = 0;
		if (temp->idx > max)
		{
			max = temp->idx;
			counter++;
			if (set)
				temp->marked = 1;
		}
		temp = temp->next;
		if (temp == NULL)
			temp = list;
		if (temp == start)
			break ;
	}
	return (counter);
}

int	len_biggest_loop(t_list *start, int set)
{
	t_list		*t;
	int			max;
	int			count;
	t_list		*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = find_loops(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
		find_loops(start, max_keep, 1);
	return (max);
}

int	distance_to_top(t_list *stack_a, int idx)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(stack_a);
	while (stack_a)
	{
		if (stack_a->idx == idx)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	if (i > len / 2)
		i -= len;
	return (i);
}

t_list	*closest_to_top(t_list *stack, int group_n, int group_size)
{
	t_list	*closest;
	t_list	*temp;
	int		proximity;
	int		cur_prox;

	proximity = INT_MAX;
	closest = NULL;
	temp = stack;
	while (temp)
	{
		if (temp->idx <= group_size * group_n && !temp->marked)
		{
			cur_prox = distance_to_top(stack, temp->idx);
			if (curr_prox_is_smaller(cur_prox, proximity))
			{
				proximity = cur_prox;
				closest = temp;
				if (proximity == 0)
					break ;
			}
		}
		temp = temp->next;
	}
	return (closest);
}
