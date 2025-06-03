# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 09:23:25 by wabolles          #+#    #+#              #
#    Updated: 2024/12/01 21:10:10 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I./inc 
NAME	=	philo
HEADER	=	./inc/includes.h

FILES	=	philosophers.c \
			./tools/usage.c \
			./tools/ft_atoi.c \
			./method/parsing.c \
			./method/set_data.c \
			./method/simulation.c

OBJS	=	$(FILES:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean