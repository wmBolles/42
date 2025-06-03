CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME		=	fixed
HEADER		=	Fixed.hpp
FILES		=	Fixed.cpp main.cpp
OBJCS		=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJCS)
	$(CC) $(OBJCS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $<
	
clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean