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
		{
			// printf("Stack is not sorted\n");
			return (0);
		}
		num = stack->content;
		stack = stack->next;
	}
	// printf("Stack is sorted\n");
	return (1);
}
 
int top_is_smallest(t_list* stack)
{
	t_list* top;

	top = stack;
	while (stack)
	{
		if ((stack)->content < top->content)
		{
			// printf("Top is not the smallest\n");
			return (0);
		}
		stack = (stack)->next;
	}
	// printf("Top is smallest\n");
	return (1);
}

// int mid_is_smallest(t_list *stack)
// {
// 	int deeznutsretard;
// }
// int one_bigger_than_two(t_list* stack)
// {
	
// }

void sort_5(t_list** stack_a, t_list** stack_b)
{
	// int min;

	t_list *top;
	top = *stack_a;
	if (!sorted(*stack_a) && mid_is_smallest(*stack_a))
		ra(stack_a, 0);
	while (!sorted(*stack_a))
	{
		if (top_is_smallest(*stack_a))
		{
			pb(stack_a, stack_b);
			// print_list(*stack_a);
			// print_list(*stack_b);
		}
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			sa(*stack_a, 0);
			// print_list(*stack_a);
			// print_list(*stack_b);
		}
		if (!top_is_smallest(*stack_a))
		{
			rra(stack_a, 0);
			// print_list(*stack_a);
			// print_list(*stack_b);
		}
		// print_list(*stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

int main (int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = get_initial_input(argv);
	stack_b = NULL;
	// print_list(stack_a);
	// printf("%d\n", top_is_smallest(stack_a, stack_a));
	sort_5(&stack_a, &stack_b);
	// print_list(stack_a);

}


// t_list* input()
// {

// }

// int main()
// {
// 	// t_list *stack_a;
// 	t_list *stack_b;
// 	int i = 0;
// 	char *permutations[9999] = {"1 2 3 4 5", "1 2 3 5 4", "1 2 4 3 5", "1 2 4 5 3", "1 2 5 3 4", "1 2 5 4 3", "1 3 2 4 5", "1 3 2 5 4", "1 3 4 2 5", "1 3 4 5 2", "1 3 5 2 4", "1 3 5 4 2", "1 4 2 3 5", "1 4 2 5 3", "1 4 3 2 5", "1 4 3 5 2", "1 4 5 2 3", "1 4 5 3 2", "1 5 2 3 4", "1 5 2 4 3", "1 5 3 2 4", "1 5 3 4 2", "1 5 4 2 3", "1 5 4 3 2", "2 1 3 4 5", "2 1 3 5 4", "2 1 4 3 5", "2 1 4 5 3", "2 1 5 3 4", "2 1 5 4 3", "2 3 1 4 5", "2 3 1 5 4", "2 3 4 1 5", "2 3 4 5 1", "2 3 5 1 4", "2 3 5 4 1", "2 4 1 3 5", "2 4 1 5 3", "2 4 3 1 5", "2 4 3 5 1", "2 4 5 1 3", "2 4 5 3 1", "2 5 1 3 4", "2 5 1 4 3", "2 5 3 1 4", "2 5 3 4 1", "2 5 4 1 3", "2 5 4 3 1", "3 1 2 4 5", "3 1 2 5 4", "3 1 4 2 5", "3 1 4 5 2", "3 1 5 2 4", "3 1 5 4 2", "3 2 1 4 5", "3 2 1 5 4", "3 2 4 1 5", "3 2 4 5 1", "3 2 5 1 4", "3 2 5 4 1", "3 4 1 2 5", "3 4 1 5 2", "3 4 2 1 5", "3 4 2 5 1", "3 4 5 1 2", "3 4 5 2 1", "3 5 1 2 4", "3 5 1 4 2", "3 5 2 1 4", "3 5 2 4 1", "3 5 4 1 2", "3 5 4 2 1", "4 1 2 3 5", "4 1 2 5 3", "4 1 3 2 5", "4 1 3 5 2", "4 1 5 2 3", "4 1 5 3 2", "4 2 1 3 5", "4 2 1 5 3", "4 2 3 1 5", "4 2 3 5 1", "4 2 5 1 3", "4 2 5 3 1", "4 3 1 2 5", "4 3 1 5 2", "4 3 2 1 5", "4 3 2 5 1", "4 3 5 1 2", "4 3 5 2 1", "4 5 1 2 3", "4 5 1 3 2", "4 5 2 1 3", "4 5 2 3 1", "4 5 3 1 2", "4 5 3 2 1", "5 1 2 3 4", "5 1 2 4 3", "5 1 3 2 4", "5 1 3 4 2", "5 1 4 2 3", "5 1 4 3 2", "5 2 1 3 4", "5 2 1 4 3", "5 2 3 1 4", "5 2 3 4 1", "5 2 4 1 3", "5 2 4 3 1", "5 3 1 2 4", "5 3 1 4 2", "5 3 2 1 4", "5 3 2 4 1", "5 3 4 1 2", "5 3 4 2 1", "5 4 1 2 3", "5 4 1 3 2", "5 4 2 1 3", "5 4 2 3 1", "5 4 3 1 2", "5 4 3 2 1"};
// 	char **perm;

// 	t_list	*new_el;
// 	t_list	*new_list;
// 	int j = 0;
// 	// printf("zzvxcv\n");
// 	while (i < 36)
// 	{
// 		perm = ft_split(permutations[i], ' ');
// 		printf("%d\n", i);
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
// 		sort_5(&new_list, &stack_b);
// 		print_list(new_list);
// 		printf("\n");
// 		i++;
// 	}
// }

