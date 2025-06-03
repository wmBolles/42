# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 07:30:31 by wabolles          #+#    #+#              #
#    Updated: 2023/11/29 09:24:33 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libftprintf.a

FMT = fmt
ROOT = .

FMT_FILES = $(FMT)/print_addr.c \
			$(FMT)/print_base.c \
			$(FMT)/print_cs.c   \
			$(FMT)/print_nbrs.c \
			$(FMT)/which_format.c \

ROOT_FILES = $(ROOT)/ft_printf.c

OBJC = $(FMT_FILES:.c=.o) $(ROOT_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	ar -rc $@ $(OBJC)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJC)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re