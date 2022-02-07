/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tes4i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 01:36:40 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/07 01:36:40 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	execute_commands(char **cmd, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		error = check_cmd(cmd[i], stack_a, stack_b);
		i++;
		if (error)
			return (1);
	}
	return (0);
}

int	check_cmd(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp(cmd, "sa\n", 3)))
		sa(stack_a, 1);
	else if (!(ft_strncmp(cmd, "sb\n", 3)))
		sb(stack_b, 1);
	else if (!(ft_strncmp(cmd, "pa\n", 3)))
		pa_no_name(stack_a, stack_b);
	else if (!(ft_strncmp(cmd, "pb\n", 3)))
		pb_no_name(stack_a, stack_b);
	else if (!(ft_strncmp(cmd, "ra\n", 3)))
		ra(stack_a, 1);
	else if (!(ft_strncmp(cmd, "rb\n", 3)))
		rb(stack_b, 1);
	else if (!(ft_strncmp(cmd, "rra\n", 4)))
		rra(stack_a, 1);
	else if (!(ft_strncmp(cmd, "rrb\n", 4)))
		rrb(stack_b, 1);
	else if (!(ft_strncmp(cmd, "ss\n", 3)))
		operation_no_name(stack_a, stack_b, 's');
	else if (!(ft_strncmp(cmd, "rr\n", 3)))
		operation_no_name(stack_a, stack_b, 'r');
	else if (!(ft_strncmp(cmd, "rrr\n", 4)))
		operation_no_name(stack_a, stack_b, 'k');
	else
		return (1);
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(char **arr, t_list *n1, t_list *n2)
{
	free_arr(arr);
	free_stack(&n1);
	free_stack(&n2);
}

char	**get_instrucitons(void)
{
	char	*word;
	char	**instrucitons;
	int		i;

	i = 0;
	instrucitons = malloc(sizeof(char *) * 9999);
	word = malloc(sizeof(char *));
	word = get_next_line(0);
	while (*word != 'X')
	{
		instrucitons[i] = word;
		word = get_next_line(0);
		i++;
	}
	free(word);
	instrucitons[i] = NULL;
	return (instrucitons);
}
