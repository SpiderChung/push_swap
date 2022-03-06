# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:57:27 by schung            #+#    #+#              #
#    Updated: 2022/03/06 19:59:21 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = headers/push_swap.h

SRC = push_swap.c utils.c leaks_and_errors.c add_func_lists.c check_input.c \
		sa_sb_ss_pa_pb.c ra_ra_rr_rra_rrb.c sorting.c big_stack_sort.c \
		small_stack_sort.c big_stack_sort_extra.c 

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
	@echo "$(YELLOW)[INFO] Push_swap and objects removed"

re: fclean all

.PHONY: all clean fclean re

#COLOURS
NOCOLOR=\033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
LMAGENTA= \033[1;35m
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'

LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'
