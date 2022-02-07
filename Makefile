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
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCs =	main.c indexing.c input_validation.c linked_lists.c \
		linked_lists2.c operations_a.c operations_b.c \
		operations_combined.c rotations.c small_math.c \
		sort_small.c sorting.c stack_b.c utils.c

SRCs_BONUS = checker.c c_main.c
OBJs_BONUS := $(SRCs:.c=.o)
OBJs := $(SRCs:.c=.o)

LIBRARY = libft.a
LIBPATH = libft

all: $(LIBRARY) $(NAME)

bonus: $(LIBRARY) $(NAME_BONUS)

$(NAME_BONUS): $(OBJs_BONUS) 
	$(CC) $(FLAGS) $(SRCs_BONUS) -o $(NAME_BONUS) $(LIBPATH)/$(LIBRARY)

$(LIBRARY): 
	$(MAKE) -C $(LIBPATH)

$(NAME): $(OBJs) 
	$(CC) $(FLAGS) $(SRCs) -o $(NAME) $(LIBPATH)/$(LIBRARY)

clean:
	$(RM) $(OBJs)

fclean: clean
	$(MAKE) fclean -C $(LIBPATH)
	$(RM) $(NAME)

re: fclean all

test:
	gcc c_main.c checker.c get_next_line.c get_next_line_utils.c indexing.c input_validation.c linked_lists.c linked_lists2.c operations_a.c operations_b.c operations_combined.c rotations.c small_math.c sort_small.c sorting.c stack_b.c utils.c libft/libft.a
