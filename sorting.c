/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:17:59 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/05 20:17:59 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int find_loops(t_list *stack, t_list *beginning, int mark)
{
	int max_idx;
	int counter;

	max_idx = -1;
	counter = 0;
	while (beginning)
	{
		if (mark)
			beginning->part_of_loop = 0;
		if (beginning->idx > max_idx)
		{
			max_idx = beginning->idx;
			counter++;
			if (mark)
				beginning->part_of_loop = 1;
		}
		beginning = beginning->next;
	}
	beginning = stack;
	return (counter);
}

int len_biggest_loop(t_list *stack, int mark)
{
	t_list *temp;
	int max_len;
	int counter;
	t_list *max_len_initial_node;

	max_len = 0;
	temp = stack;
	while(temp)
	{
		counter = find_loops(stack, temp, 0);
		if (counter > max_len)
		{
			max_len = counter;
			max_len_initial_node = temp;
		}
		temp = temp->next;
	}
	if (mark)
		find_loops(stack, max_len_initial_node, 1);
	return (max_len);
}

int get_bigger_num(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
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

int curr_prox_is_smaller(int n1, int n2)
{
	return (ft_abs(n1) < ft_abs(n2));
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
		if (temp->idx <= group_size * group_n && !temp->part_of_loop)
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


void	rotate_both(t_list *stack_a, t_list *stack_b, int *r_a, int *r_b)
{
	while (*r_a > 0 && *r_b > 0)
	{
		(*r_a)--;
		(*r_b)--;
		rr(&stack_a, &stack_b);
	}
	while (*r_a < 0 && *r_b < 0)
	{
		(*r_a)++;
		(*r_b)++;
		rrr(&stack_a, &stack_b);
	}
}

void choose_rotation(t_list **stack_a, t_list **stack_b, int r_a, int r_b)
{
	rotate_both(*stack_a, *stack_b, &r_a, &r_b);
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

int greater_num(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

// int	time_to_swap(t_list *list)
// {
// 	t_list	fake;
// 	t_list	fake2;
// 	int		count;
// 	int		count2;

// 	fake.next = &fake2;
// 	fake.idx = list->next->idx;
// 	fake2.next = list->next->next;
// 	fake2.idx = list->idx;
// 	count = len_biggest_loop(list, 0);
// 	count2 = len_biggest_loop(&fake, 0);
// 	if (count2 > count)
// 		return (1);
// 	return (0);
// }

void sort(t_list **stack_a, t_list **stack_b)
{
	// int biggest_loop_n;
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
	int i = 0;
	while (cur_group < groups + 1)
	// while (i < 20)
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
			sa(*stack_a, 0);
			len_biggest_loop(*stack_a, 1);
		}
		else if (!(*stack_a)->part_of_loop && distance_top == 0)
		{
			pb(stack_a, stack_b);
			stack_size--;
		}
		else if (cur_group == 1)
			rr(stack_a, stack_b);
		else
		{
			r_a = greater_num(-1, distance_top);
			r_a = !greater_num(1, r_a);
			choose_rotation(stack_a, stack_b, r_a, r_b);
		}
		i++;
	}

}
