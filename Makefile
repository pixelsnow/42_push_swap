# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 18:38:50 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/24 21:45:46 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
		swap.c \
		stack_utils.c \
		push.c \
		rotate.c

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
