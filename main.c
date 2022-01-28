/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:12:38 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 18:11:24 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = -1;
	if (argc > 2)
		i = validate_input(argv);
	else
	{
		return ((write(2, "ErroR\n", 6)));
	}
	if (i == -1)
		return (write(2, "Error\n", 6));
	stack_a = get_initial_input(argv);
	stack_b = 0;
	print_list(stack_a);
	return (0);
}
