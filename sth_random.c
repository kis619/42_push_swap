#include "push_swap.h"

t_list	*get_highest_num(t_list *stack)
{
	int		i;
	t_list	*biggest;

	biggest = NULL;
	i = stack->content;
	while (stack)
	{
		if (stack->content > i)
		{
			i = stack->content;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

void	ft_index(t_list *stack, int max_idx)
{
	t_list	*biggest;
	t_list	*first;
	int		i;

	first = stack;
	biggest = get_highest_num(stack);
	i = INT_MIN;
	while (-1 < max_idx)
	{
		while (stack)
		{
			if (stack->idx == -1 && stack->content > i)
			{
				i = stack->content;
				biggest = stack;
			}
			stack = stack->next;
		}
		biggest->idx = max_idx;
		max_idx--;
		stack = first;
		i = INT_MIN;
	}
}


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

//creates a new node
t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->idx = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

//returns number of elements in list
int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

//returns the last node
t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//returns the penultimate node
t_list	*ft_lstpenultimate(t_list *lst)
{
	t_list	*second_to_last;

	while (lst->next != NULL)
	{
		second_to_last = lst;
		lst = lst->next;
	}
	return (second_to_last);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	if (*lst)
	{
		last_element = ft_lstlast(*lst);
		last_element->next = new;
	}
	else
		*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*lst_p;
	t_list	*next;

	lst_p = *lst;
	while (lst_p != 0)
	{
		next = lst_p->next;
		ft_lstdelone(lst_p, del);
		lst_p = next;
	}
	*lst = 0;
}

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst != 0 && f != 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_list;
	t_list	*new_el;

	if (!lst || !f)
		return (NULL);
	new_el = ft_lstnew(f(lst->content));
	if (!new_el)
		return (NULL);
	new_list = new_el;
	while (lst->next)
	{
		lst = lst->next;
		new_el = ft_lstnew(f(lst->content));
		if (!new_el)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_el);
	}
	return (new_list);
}

void	sa(t_list **stack, int called)
{
	t_list	*temp;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return ;
	third = (*stack)->next->next;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = third;
	if (!called)
		print_func_name(__func__);
}


void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	ft_lstadd_front(stack_a, top_b);
	print_func_name(__func__);
}

void	ra(t_list **stack_a, int called)
{
	t_list	*top;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	top = *stack_a;
	(*stack_a) = (*stack_a)->next;
	last->next = top;
	top->next = NULL;
	if (!called)
		print_func_name(__func__);
}

void	rra(t_list **stack_a, int called)
{
	t_list	*last;
	t_list	*sec_last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	sec_last = ft_lstpenultimate(*stack_a);
	sec_last->next = NULL;
	last->next = *stack_a;
	(*stack_a) = last;
	if (!called)
		print_func_name(__func__);
}

void	sb(t_list *stack_b, int called)
{
	int	temp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
	if (!called)
		print_func_name(__func__);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	
	if (ft_lstsize(*stack_a) < 1)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	ft_lstadd_front(stack_b, top_a);
	print_func_name(__func__);
}

void	rb(t_list **stack_b, int called)
{
	t_list	*top;
	t_list	*last;
	t_list	*second;


	if (ft_lstsize(*stack_b) < 2)
		return ;
	top = *stack_b;
	second = top->next;
	last = ft_lstlast(*stack_b);
	(*stack_b) = second;
	top->next = NULL;
	last->next = top;
	if (!called)
		print_func_name(__func__);
}



void	rrb(t_list **stack_b, int called)
{
	t_list	*last;
	t_list	*penultimate;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	last = ft_lstlast(*stack_b);
	penultimate = ft_lstpenultimate(*stack_b);
	last->next = *stack_b;
	(*stack_b) = last;
	penultimate->next = NULL;
	if (!called)
		print_func_name(__func__);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(*stack_b, 1);
	print_func_name(__func__);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	print_func_name(__func__);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	print_func_name(__func__);
}

int	top_is_smallest(t_list *stack)
{
	t_list	*top;

	top = stack;
	while (stack)
	{
		if ((stack)->content < top->content)
			return (0);
		stack = (stack)->next;
	}
	return (1);
}

int	mid_is_smallest(t_list *stack)
{
	int	first;
	int	second;
	int	third;
	int	fourth;
	int	fifth;

	first = (*stack).content;
	second = (*stack).next->content;
	third = (*stack).next->next->content;
	fourth = (*stack).next->next->next->content;
	fifth = (*stack).next->next->next->next->content;
	if (third < second && third < first && third < fourth && third < fifth)
		return (1);
	return (0);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (!sorted(*stack_a) && mid_is_smallest(*stack_a))
	{
		if ((*stack_a)->content != 5)
			ra(stack_a, 0);
	}
	while (!sorted(*stack_a))
	{
		if (top_is_smallest(*stack_a))
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 0);
		if (!top_is_smallest(*stack_a))
			rra(stack_a, 0);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_2_3_4(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 2 && (*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		ra(stack_a, 0);
	while (!sorted(*stack_a))
	{
		if (top_is_smallest(*stack_a))
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 0);
		if (!top_is_smallest(*stack_a))
			rra(stack_a, 0);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

int find_loops(t_list *list, t_list *start, int set)
{
	t_list	*temp;
	int max_tag;
	int count;

	max_tag = -1;
	count = 0;
	temp = start;
	while (temp)
	{
		if (set)
			temp->marked = 0;
		if (temp->idx > max_tag)
		{
			max_tag = temp->idx;
			count++;
			if (set)
				temp->marked = 1;
		}
		temp = temp->next;
		if (temp == NULL)
			temp = list;
		if (temp == start)
			break ;
	}
	start = list;
	return (count);
}

int	len_biggest_loop(t_list *start, int set)
{
	t_list		*t;
	int			max;
	int			count;
	t_list		*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = find_loops(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
		find_loops(start, max_keep, 1);
	return (max);
}

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

int distance_to_top(t_list *stack_a, int idx)
{
	int len;
	int i;

	i = 0;
	len  = ft_lstsize(stack_a); 
	while (stack_a)
	{
		if (stack_a->idx == idx)
			break;
		i++;
		stack_a = stack_a->next;
	}
	if (i > len / 2)
		i -= len;
	return (i);
}

int curr_prox_is_smaller(int n1, int n2)
{
	return (ft_abs(n1) < ft_abs(n2));
}

t_list *closest_to_top(t_list *stack, int group_n, int group_size)
{
	t_list *closest;
	t_list *temp;
	int proximity;
	int cur_prox;

	proximity = INT_MAX;
	closest = NULL;
	temp = stack;
	while (temp)
	{
		if (temp->idx <= group_size * group_n && !temp->marked)
		{
			cur_prox = distance_to_top(stack, temp->idx);
			if (curr_prox_is_smaller(cur_prox, proximity))
			{
				proximity = cur_prox;
				closest = temp;
				if (proximity == 0)
					break ;
			}
		}
		temp = temp->next;
	}
	return (closest);
}

int time_to_swap(t_list *stack)
{
	t_list first;
	t_list second;

	first.next = &second;
	first.idx = stack->next->idx;
	second.next = stack->next->next;
	second.idx = stack->idx;
	if (len_biggest_loop(stack, 0) < len_biggest_loop(&first, 0))
		return (1);
	return (0);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, int *r_a, int *r_b)
{
	while (*r_a > 0 && *r_b > 0)
	{
		(*r_a)--;
		(*r_b)--;
		rr(stack_a, stack_b);
	}
	while (*r_a < 0 && *r_b < 0)
	{
		(*r_a)++;
		(*r_b)++;
		rrr(stack_a, stack_b);
	}
}

void choose_rotation(t_list **stack_a, t_list **stack_b, int r_a, int r_b)
{
	rotate_both(stack_a, stack_b, &r_a, &r_b);
	while (r_a > 0)
	{
		r_a--;
		ra(stack_a, 0);
	}
	while (r_a < 0)
	{
		r_a++;
		rra(stack_a, 0);
	}
	while (r_b > 0)
	{
		r_b--;
		rb(stack_b, 0);
	}
	while (r_b < 0)
	{
		r_b++;
		rrb(stack_b, 0);
	}
}

int greater_num(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

void	print_list_1(t_list *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->marked);
		node = node->next;
	}
	printf("\n");
}
void sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int stack_size;
	int groups;
	int group_size;
	int cur_group = 1;
	int distance_top;
	int r_a;
	int r_b = 0;
	t_list *temp;

	stack_size = ft_lstsize(*stack_a);
	len_biggest_loop(*stack_a, 1);
	groups = get_bigger_num(1, stack_size / 150);
	group_size = stack_size / groups;
	while (cur_group <= groups + 1)
	{
		temp = closest_to_top(*stack_a, cur_group, group_size);
		if (temp == NULL)
		{	
			cur_group++;
			continue ;
		}
		distance_top = distance_to_top(*stack_a, temp->idx);
		if (time_to_swap(*stack_a))
		{
			sa(stack_a, 0);
			len_biggest_loop(*stack_a, 1);
		}
		else if (!(*stack_a)->marked && distance_top == 0)
		{
			pb(stack_a, stack_b);
			stack_size--;
		}
		else if (cur_group == 1)
			rr(stack_a, stack_b);
		else
		{
			r_a = get_bigger_num(-1, distance_top);
			r_a = get_smaller_num(1, r_a);
			choose_rotation(stack_a, stack_b, r_a, r_b);
		}
	}
	initialise_b(stack_a, stack_b, argc);
}

int	distance_to_b(int idx, int size)
{
	if (idx >= size / 2)
		idx -= size;
	return (idx);
}

int distance_to_a(t_list *stack_a, int idx, int size)
{
	t_list *temp;
	t_list *last;
	int curr_and_min[2];
	int i;

	i = 0;
	temp = stack_a;
	last = ft_lstlast(stack_a);
	curr_and_min[1] = INT_MAX;
	while (temp)
	{
		if ((last->idx > temp->idx && (idx < temp->idx || idx > last->idx))
			|| (idx < temp->idx && idx > last->idx))
		{
			curr_and_min[0] = i;
			if (curr_and_min[0] > size / 2)
				curr_and_min[0] -= size;
			if (ft_abs(curr_and_min[0]) < curr_and_min[1])
				curr_and_min[1] = curr_and_min[0];
		}
		last = temp;
		temp = temp->next;
		i++;
	}
	return (curr_and_min[1]);
}


void calculate_b_rotation(t_list *stack_a, t_list *stack_b, int *r_a, int *r_b, int argc)
{
	int max_dist = INT_MAX;
	int i;
	int total_dist;
	int dist_b;
	int dist_a;
	int len_a;

	t_list *temp;
	temp = stack_b;
	len_a = ft_lstsize(stack_a);
	i = 0;

	while (temp)
	{
		dist_b = distance_to_b(i++, argc - len_a);
		dist_a = distance_to_a(stack_a, temp->idx, len_a);
		total_dist = ft_abs(dist_a) + ft_abs(dist_b);
		if (dist_a > 0 && dist_b > 0)
			total_dist -= get_smaller_num(dist_a, dist_b);
		else if (dist_a < 0 && dist_b < 0)
			total_dist += get_bigger_num(dist_a, dist_b);
		if (total_dist < max_dist)
		{
			max_dist = total_dist;
			*r_a = dist_a;
			*r_b = dist_b;
		}
		temp = temp->next;
	}

}

void initialise_b(t_list **stack_a, t_list **stack_b, int argc)
{
	int r_a;
	int r_b;

	while (*stack_b)
	{
		calculate_b_rotation(*stack_a, *stack_b, &r_a, &r_b, argc);
		choose_rotation(stack_a, stack_b, r_a, r_b);
		pa(stack_a, stack_b);
	}
	choose_rotation(stack_a, stack_b, distance_to_top(*stack_a, 0), 0);
}


/*
	Input: list of strings.
	Applies atoi to the elements, makes nodes and links them in a Linked list.
*/
t_list	*get_initial_input(char *argv[])
{
	int		i;
	t_list	*new_el;
	t_list	*new_list;

	new_list = ft_lstnew(ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		new_el = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&new_list, new_el);
		i++;
	}
	return (new_list);
}

/* 
	prints the content of all nodes
*/
void	print_list(t_list *node)

{
	while (node != NULL)
	{
		printf(" %d ", node->content);
		node = node->next;
	}
	printf("\n");
}

void print_func_name(const char *str)
{
	write(1, ft_strjoin(str, "\n"), ft_strlen(str) + 1);
}

int sorted(t_list *stack)
{
	int num;

	num = stack->content;
	while (stack)
	{
		if (stack->content < num)
			return (0);
		num = stack->content;
		stack = stack->next;
	}
	return (1);
}

void	print_list_idx(t_list *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->idx);
		node = node->next;
	}
	printf("\n");
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(new_string))
		return (NULL);
	ft_strlcpy(new_string, s1, s1_len + 1);
	ft_strlcpy(new_string + s1_len, s2, s2_len + 1);
	return (new_string);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		++p;
	return (p - s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	
	i = 0;
	if (argc > 1)
		i = validate_input(argv);
	else
		return (0);
	if (i == -1)
		return (write(2, "Error\n", 6));
	stack_a = get_initial_input(argv);
	stack_b = NULL;
	if (argc <= 4)
		sort_2_3_4(&stack_a, &stack_b);
	if (argc == 5)
		sort_5(&stack_a, &stack_b);
	ft_index(stack_a, argc - 2);
	// print_list(stack_a);
	// printf("Swap value %d\n", time_to_swap(stack_a));
	sort(&stack_a, &stack_b, argc - 1);
	// printf("\n\n");
	// print_list(stack_a);

	return (0);
}


