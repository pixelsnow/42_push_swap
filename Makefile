# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 18:38:50 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/22 18:42:59 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror
INC = -I.

all: $(NAME)
	
$(NAME): $(OBJ) 
	cc $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	cc -c $(FLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
