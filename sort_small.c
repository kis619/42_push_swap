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

int sorted(t_list *stack)
{
	int num;

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
	if (ft_lstsize(*stack_a) > 2 && (*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
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

// int main (int argc, char *argv[])
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;

// 	stack_a = get_initial_input(argv);
// 	stack_b = NULL;
// 	// print_list(stack_a);
// 	// printf("%d\n", top_is_smallest(stack_a, stack_a));
// 	sort_5(&stack_a, &stack_b);
// 	// print_list(stack_a);

// }

// t_list* input()
// {

// }

// int main()
// {
// 	// t_list *stack_a;
// 	t_list *stack_b;
// 	int i = 0;
// 	char *permutations[9999] = {"1 2 3 4 5", "1 2 3 5 4", "1 2 4 3 5", "1 2 4 5 3", "1 2 5 3 4","1 2 5 4 3", "1 3 2 4 5", "1 3 2 5 4", "1 3 4 2 5", "1 3 4 5 2", "1 3 5 2 4", "1 3 5 4 2", "1 4 2 3 5", "1 4 2 5 3", "1 4 3 2 5", "1 4 3 5 2", "1 4 5 2 3", "1 4 5 3 2", "1 5 2 3 4", "1 5 2 4 3", "1 5 3 2 4", "1 5 3 4 2", "1 5 4 2 3", "1 5 4 3 2", "2 1 3 4 5", "2 1 3 5 4", "2 1 4 3 5", "2 1 4 5 3", "2 1 5 3 4", "2 1 5 4 3", "2 3 1 4 5", "2 3 1 5 4", "2 3 4 1 5", "2 3 4 5 1", "2 3 5 1 4", "2 3 5 4 1", "2 4 1 3 5", "2 4 1 5 3", "2 4 3 1 5", "2 4 3 5 1", "2 4 5 1 3", "2 4 5 3 1", "2 5 1 3 4", "2 5 1 4 3", "2 5 3 1 4", "2 5 3 4 1", "2 5 4 1 3", "2 5 4 3 1", "3 1 2 4 5", "3 1 2 5 4", "3 1 4 2 5", "3 1 4 5 2", "3 1 5 2 4", "3 1 5 4 2", "3 2 1 4 5", "3 2 1 5 4", "3 2 4 1 5", "3 2 4 5 1", "3 2 5 1 4", "3 2 5 4 1", "3 4 1 2 5", "3 4 1 5 2", "3 4 2 1 5", "3 4 2 5 1", "3 4 5 1 2", "3 4 5 2 1", "3 5 1 2 4", "3 5 1 4 2", "3 5 2 1 4", "3 5 2 4 1", "3 5 4 1 2", "3 5 4 2 1", "4 1 2 3 5", "4 1 2 5 3", "4 1 3 2 5", "4 1 3 5 2", "4 1 5 2 3", "4 1 5 3 2", "4 2 1 3 5", "4 2 1 5 3", "4 2 3 1 5", "4 2 3 5 1", "4 2 5 1 3", "4 2 5 3 1", "4 3 1 2 5", "4 3 1 5 2", "4 3 2 1 5", "4 3 2 5 1", "4 3 5 1 2", "4 3 5 2 1", "4 5 1 2 3", "4 5 1 3 2", "4 5 2 1 3", "4 5 2 3 1", "4 5 3 1 2", "4 5 3 2 1", "5 1 2 3 4", "5 1 2 4 3", "5 1 3 2 4", "5 1 3 4 2", "5 1 4 2 3", "5 1 4 3 2", "5 2 1 3 4", "5 2 1 4 3", "5 2 3 1 4", "5 2 3 4 1", "5 2 4 1 3", "5 2 4 3 1", "5 3 1 2 4", "5 3 1 4 2", "5 3 2 1 4", "5 3 2 4 1", "5 3 4 1 2", "5 3 4 2 1", "5 4 1 2 3", "5 4 1 3 2", "5 4 2 1 3", "5 4 2 3 1", "5 4 3 1 2", "5 4 3 2 1"};
// 	char **perm;

// 	t_list	*new_el;
// 	t_list	*new_list;
// 	int j = 0;
// 	// printf("zzvxcv\n");
// 	while (i < 120)
// 	{
// 		perm = ft_split(permutations[i], ' ');

// 		new_list = ft_lstnew(ft_atoi(perm[0]));
// 		j = 1;
// 		while (perm[j])
// 		{
// 			new_el = ft_lstnew(ft_atoi(perm[j]));
// 			ft_lstadd_back(&new_list, new_el);
// 			j++;
// 		}
// 		// stack_a = input();
// 		stack_b = NULL;
// 		print_list(new_list);
// 		print_list(new_list);
// 		int count = 0;
// 		count = sort_5(&new_list, &stack_b);
// 		printf("Test number: %d\nNumber of operations: %d\n", i, count);
// 		printf("\n");
// 		i++;
// 	}
// }
