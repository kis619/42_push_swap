/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:12:38 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/02 13:59:04 by kmilchev         ###   ########.fr       */
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

// int one_bigger_than_two(t_list* stack)
// {
	
// }

void sort_5(t_list** stack_a, t_list** stack_b)
{
	// int min;

	// t_list *top;
	// top = *stack_a;
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

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = -1;
	if (argc > 2)
		i = validate_input(argv);
	else
		return ((write(2, "ErroR\n", 6)));
	if (i == -1)
		return (write(2, "Error\n", 6));
	stack_a = get_initial_input(argv);
	stack_b = NULL;
	print_list(stack_a);
	sort_5(&stack_a, &stack_b);
	// printf("\n");
	print_list(stack_a);
	return (0);
}
