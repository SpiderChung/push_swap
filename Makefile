# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2022/02/13 22:26:18 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = headers/push_swap.h

SRC = push_swap.c push_swap_utils.c push_swap_functions.c push_swap_input.c

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
	@echo "[INFO] [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ)
	@echo "[INFO] Removed push_swap objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@make fclean -C libft
	@echo "[INFO] Push_swap and objects removed "

re: fclean all

.PHONY: all clean fclean re