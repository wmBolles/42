# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 06:57:18 by wabolles          #+#    #+#              #
#    Updated: 2024/07/25 10:46:33 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -I./inc 
HEADER = inc/push_swap.h
NAME = push_swap

UTILS = utils/libc/split.c				\
		utils/libc/ft_atoi.c			\
		utils/libc/tools.c				\
		utils/libc/list.c				\
		utils/parsing.c					\
		push_swap.c						\
		utils/moves.c utils/moves2.c	\
		utils/sort.c					\
		utils/small_sorts.c				
		
PUSH_SWAP_FILES = $(UTILS) $(PRINTF_FILES) $(GC)
PUSH_SWAP_OBJ = $(PUSH_SWAP_FILES:.c=.o)

all: $(NAME)

$(NAME) : $(PUSH_SWAP_OBJ) 
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(PUSH_SWAP_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean