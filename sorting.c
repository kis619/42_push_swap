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

void sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int stack_size;
	int groups;
	int group_size;
	int cur_group = 1;
	int distance_top;
	int r_a;
	int r_b = 0;
	t_list *temp;

	stack_size = ft_lstsize(*stack_a);
	len_biggest_loop(*stack_a, 1);
	groups = get_bigger_num(1, stack_size / 150);
	group_size = stack_size / groups;
	while (cur_group <= groups + 1)
	{
		temp = closest_to_top(*stack_a, cur_group, group_size);
		if (temp == NULL)
		{	
			cur_group++;
			continue ;
		}
		distance_top = distance_to_top(*stack_a, temp->idx);
		if (time_to_swap(*stack_a))
		{
			sa(stack_a, 0);
			len_biggest_loop(*stack_a, 1);
		}
		else if (!(*stack_a)->marked && distance_top == 0)
		{
			pb(stack_a, stack_b);
			stack_size--;
		}
		else if (cur_group == 1)
			rr(stack_a, stack_b);
		else
		{
			r_a = get_bigger_num(-1, distance_top);
			r_a = get_smaller_num(1, r_a);
			choose_rotation(stack_a, stack_b, r_a, r_b);
		}
	}
	initialise_b(stack_a, stack_b, argc);
}

int find_loops(t_list *list, t_list *start, int set)
{
	t_list	*temp;
	int max_tag;
	int count;

	max_tag = -1;
	count = 0;
	temp = start;
	while (temp)
	{
		if (set)
			temp->marked = 0;
		if (temp->idx > max_tag)
		{
			max_tag = temp->idx;
			count++;
			if (set)
				temp->marked = 1;
		}
		temp = temp->next;
		if (temp == NULL)
			temp = list;
		if (temp == start)
			break ;
	}
	start = list;
	return (count);
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

int distance_to_top(t_list *stack_a, int idx)
{
	int len;
	int i;

	i = 0;
	len  = ft_lstsize(stack_a); 
	while (stack_a)
	{
		if (stack_a->idx == idx)
			break;
		i++;
		stack_a = stack_a->next;
	}
	if (i > len / 2)
		i -= len;
	return (i);
}

t_list *closest_to_top(t_list *stack, int group_n, int group_size)
{
	t_list *closest;
	t_list *temp;
	int proximity;
	int cur_prox;

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


int time_to_swap(t_list *stack)
{
	t_list first;
	t_list second;

	first.next = &second;
	first.idx = stack->next->idx;
	second.next = stack->next->next;
	second.idx = stack->idx;
	if (len_biggest_loop(stack, 0) < len_biggest_loop(&first, 0))
		return (1);
	return (0);
}
