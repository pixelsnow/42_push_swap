# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 18:38:50 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/26 19:12:47 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
		input.c \
		rank.c \
		sort_tiny.c \
		sort_small.c \
		sort_large.c \
		stack_swap.c \
		stack_utils.c \
		stack_push.c \
		stack_rotate.c \
		stack_reverse_rotate.c \
		stack_constructors.c \
		stack_destructors.c \

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a
LIBFTDIR = libft

FLAGS = -Wall -Wextra -Werror
INC = -I. -I$(LIBFTDIR)

all: $(LIBFT) $(NAME) 
	
$(NAME): $(OBJ)
	cc $(OBJ) $(INC) $(LIBFT) -o $(NAME)

$(LIBFT): 
	make -C $(LIBFTDIR)

%.o: %.c
	cc -c $(FLAGS) $^

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
