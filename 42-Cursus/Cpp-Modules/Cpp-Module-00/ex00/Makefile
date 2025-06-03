# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 00:30:59 by wabolles          #+#    #+#              #
#    Updated: 2025/02/23 09:50:48 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -c -std=c++98
NAME		=	megaphone
FILE		=	megaphone.cpp
OBJC		=	$(FILE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(FILE) -o $(NAME)

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean