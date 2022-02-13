/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:01:30 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/07 04:01:30 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instrucitons;
	int		i;

	if (argc == 1)
		return (0);
	i = validate_input(argv);
	if (i == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = get_initial_input(argv);
	stack_b = NULL;
	instrucitons = get_instrucitons();
	i = execute_commands(instrucitons, &stack_a, &stack_b);
	if (i == 1)
		write(2, "Error\n", 6);
	else if (sorted(stack_a) && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(instrucitons, stack_a, stack_b);
}