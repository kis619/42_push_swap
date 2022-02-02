/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:40 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/02 11:55:34 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* Checks if the input consists only of integers
	returns -1 for invalid input
	returns 0 for valid input
*/
int		validate_input(char *l[]);

/*
	returns 0 for non-integers
	returns 1 for integers
*/
int		is_an_integer(const char *str_num);

///linked_lists
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
t_list	*ft_lstnew(int content);
t_list	*ft_lstpenultimate(t_list *lst);
/* 
	prints the content of all nodes
*/
void	print_list(t_list *node);

void print_func_name(const char *str);
/*
	Input: list of strings.
	Applies atoi to the elements, makes nodes and links them in a Linked list.
*/
t_list	*get_initial_input(char *argv[]);

//OPERATIONS
void	sa(t_list *stack_a, int called);
void	ra(t_list **stack_a, int called);
void	rra(t_list **stack_a, int called);
void	sb(t_list *stack_b, int called);
void	rb(t_list **stack_b, int called);
void	rrb(t_list **stack_b, int called);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif