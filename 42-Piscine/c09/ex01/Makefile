# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 21:41:24 by wabolles          #+#    #+#              #
#    Updated: 2023/08/03 22:24:29 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${INCLUDES:.c=.o}

HEADERS = includes/

NAME = libft.a

CCFLAGS = -Wall -Wextra -Werror

COMPILER = cc

%.o: %.c
	$(COMPILER) $(CCFLAGS) -c $< -o $@ -I $(HEADERS)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
