/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:12:10 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 22:03:16 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	returns 0 for non-integers
	returns 1 for integers
*/
int	is_an_integer(const char *str_num)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str_num);
	if (len > 11)
		return (1);
	if (len > 10 && str_num[0] != '-')
		return (1);
	if (len > 10 && str_num[0] == '-')
	{
		i = ft_strncmp(str_num, "-2147483648", 11);
		if (i > 0)
			return (1);
	}
	if (len == 10 && str_num)
	{
		i = ft_strncmp(str_num, "2147483647", 11);
		if (i > 0)
			return (1);
	}
	return (0);
}

/* returns 0 if there aren't repetitions
	returns 1 if there are */
int	there_are_repeats(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* 
	Checks if the input consists only of integers
	returns -1 for invalid input
	returns 0 for valid input
*/
int	validate_input(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (!(ft_isdigit(argv[i][j])))
				return (-1);
			j++;
		}
		if (is_an_integer(argv[i]))
			return (-1);
		i++;
	}
	if (there_are_repeats(argv) == 1)
		return (-1);
	return (0);
}
