/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:18:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/06 21:18:13 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_bigger_num(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int get_smaller_num(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

int ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}