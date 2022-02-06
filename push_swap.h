/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:40 by kmilchev          #+#    #+#             */
/*   Updated: 2022/02/07 00:26:07 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				idx;
	int				marked;
	struct s_list	*next;
}	t_list;

typedef struct everything
{
	int	stack_size;
	int	groups;
	int	group_size;
	int	cur_group;
	int	d_top;
	int	r_a;
	int	r_b;
}			t_data;

typedef struct distance
{
	int	max_dist;
	int	i;
	int	total;
	int	b;
	int	a;
	int	len_a;
}		t_dist;

///LINKED_LISTS
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
t_list	*ft_lstnew(int content);
t_list	*ft_lstpenultimate(t_list *lst);

//OPERATIONS
void	sa(t_list **stack_a, int called);
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
void	free_stack(t_list **list);

//INPUT
int		validate_input(char *l[]);
int		is_an_integer(const char *str_num);
void	print_func_name(const char *str);
t_list	*get_initial_input(char *argv[]);
void	ft_index(t_list *stack, int max_idx);

//SORT
int		sorted(t_list *stack);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_2_3_4(t_list **stack_a, t_list **stack_b);
int		top_is_smallest(t_list *stack);
int		mid_is_smallest(t_list *stack);
void	sort(t_list **stack_a, t_list **stack_b, t_data data, int argc);
void	initialise_b(t_list **stack_a, t_list **stack_b, int argc);
void	calc_b_r(t_list *stack_a, t_list *stack_b, int r_a_b[2], int argc);
void	choose_rotation(t_list **stack_a, t_list **stack_b, int r_a, int r_b);
int		distance_to_b(int idx, int size);
int		distance_to_a(t_list *stack_a, int idx, int size);

//BACK_TO_SCHOOL
int		big(int n1, int n2);
int		small(int n1, int n2);
int		ft_abs(int num);

//MISCELANIOUS
t_list	*get_highest_num(t_list *stack);
t_data	fill_data(t_list **stack_a);
int		find_loops(t_list *stack, t_list *beginning, int mark);
int		len_biggest_loop(t_list *stack, int mark);
int		curr_prox_is_smaller(int n1, int n2);
int		distance_to_top(t_list *stack_a, int idx);
t_list	*closest_to_top(t_list *stack, int group_n, int group_size);
int		time_to_swap(t_list *stack);
#endif