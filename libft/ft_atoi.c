/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:18:54 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/25 15:18:54 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;

	num = 0;
	i = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			i = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	if (num > 2147483647)
		return (0);
	return (i * num);
}

static int	ft_isspace(char c)
{
	return ((c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v'));
}

// #include <stdio.h>
// int main ()
// {
// 	printf("%d\n", ft_atoi("8"));
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("-21474836491"));
// 	// printf("%d\n", ft_atoi("7"));
// 	// printf("%d\n", ft_atoi("7"));
// 	// printf("%d\n", ft_atoi("7"));
// 	// printf("%d\n", ft_atoi("7"));
// 	// printf("%d\n", ft_atoi("7"));
// 	return (0);
// }