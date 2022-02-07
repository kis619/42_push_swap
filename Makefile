# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 21:45:59 by kmilchev          #+#    #+#              #
#    Updated: 2022/01/21 21:45:59 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

PUSH_MAIN = 		push_swap_all/main.c

SRCs =				push_swap_all/operations_combined.c \
					push_swap_all/indexing.c \
					push_swap_all/input_validation.c \
					push_swap_all/linked_lists.c \
					push_swap_all/linked_lists2.c \
					push_swap_all/operations_a.c \
					push_swap_all/operations_b.c \
					push_swap_all/rotations.c \
					push_swap_all/small_math.c \
					push_swap_all/sort_small.c \
					push_swap_all/sorting.c \
					push_swap_all/stack_b.c \
					push_swap_all/utils.c

SRCs_BONUS =		my_checker/c_main.c \
					my_checker/checker.c \
					get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

OBJ_PUSH_MAIN :=	$(PUSH_MAIN:.c=.o)
OBJs := 			$(SRCs:.c=.o)
OBJs_BONUS :=		$(SRCs_BONUS:.c=.o)

FLAGS =				-Wall -Werror -Wextra
CC =				gcc
LIBRARY =			libft.a
LIBPATH =			libft

all: $(LIBRARY) $(NAME)

bonus: $(OBJs_BONUS) $(LIBRARY)
	$(CC) $(FLAGS) $(SRCs_BONUS) $(SRCs) -o $(NAME_BONUS) $(LIBPATH)/$(LIBRARY)

$(LIBRARY): 
	$(MAKE) -C $(LIBPATH)

$(NAME): $(OBJs) $(OBJ_PUSH_MAIN)
	$(CC) $(FLAGS) $(OBJ_PUSH_MAIN) $(OBJs) -o $(NAME) $(LIBPATH)/$(LIBRARY)

clean:
	$(RM) $(OBJs)
	$(RM) $(OBJs_BONUS)
	$(RM) $(OBJ_PUSH_MAIN)

fclean: clean
	$(MAKE) fclean -C $(LIBPATH)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) *.exe

re: fclean all