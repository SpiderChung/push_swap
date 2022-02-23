# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2022/02/23 19:44:08 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = headers/push_swap.h

SRC = push_swap.c utils.c leaks_and_errors.c add_func_lists.c check_input.c \
		instructions_1.c instructions_2.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

%.o: %.c $(HEADER)
	$(CC) -I $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -I $(HEADER) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "$(LMAGENTA)[INFO] [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ)
	@echo "$(YELLOW)[INFO] Removed push_swap objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@make fclean -C libft
	@echo "$(YELLOW)[INFO] Push_swap and objects removed "

re: fclean all

.PHONY: all clean fclean re

#COLOURS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
LMAGENTA= \033[1;35m
