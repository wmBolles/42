# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 09:08:58 by wabolles          #+#    #+#              #
#    Updated: 2025/02/23 10:54:18 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME		=	numberbook
HEADERS		=	./PhoneBook.hpp ./Contact.hpp
FILES		=	main.cpp PhoneBook.cpp Contact.cpp
OBJCS		=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJCS)
	$(CC) $(OBJCS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $<
	
clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
