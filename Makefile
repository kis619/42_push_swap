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
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCs = main.c input_validation.c linked_lists.c linked_lists2.c operations_a.c operations_b.c operations_combined.c utils.c sort_5.c indexing.c sorting.c stack_b.c
OBJs := $(SRCs:.c=.o)
LIBRARY = libft.a
LIBPATH = libft

all: $(LIBRARY) $(NAME)

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
	gcc -Wall -Werror -Wextra main.c linked_lists2.c linked_lists.c operations_a.c operations_b.c operations_combined.c utils.c input_validation.c $(LIBPATH)/$(LIBRARY)

optest:
	gcc test_operations.c linked_lists2.c linked_lists.c operations_a.c operations_b.c operations_combined.c utils.c input_validation.c libft/libft.a

sort5:
	gcc sort_5.c linked_lists2.c linked_lists.c operations_a.c operations_b.c operations_combined.c utils.c input_validation.c libft/libft.a



