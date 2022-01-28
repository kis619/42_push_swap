/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:10:59 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/28 18:04:56 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main ()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew(5);
	node2 = ft_lstnew(10);
	node3 = ft_lstnew(76);
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	print_list(node1);
	printf("\n");
	// rra(&node1);
	// printList(node1);
	// printf("\n");
	// rra(&node1);
	// printList(node1);
	// printf("\n");
	// // printList(node1);
	// rra(&node1);
	// printList(node1);
	// printf("\n");
	t_list *node1b;
	node1b = ft_lstnew(69);
	ft_lstadd_back(&node1b, ft_lstnew(70));
	ft_lstadd_back(&node1b, ft_lstnew(71));
	print_list(node1b);
	printf("\n________________\n");
	// rrr(&node1, &node1b);
	// printList(node1);
	pb(&node1, &node1b);
	printf("\n");
	print_list(node1);
	printf("\n");
	print_list(node1b);
	
}