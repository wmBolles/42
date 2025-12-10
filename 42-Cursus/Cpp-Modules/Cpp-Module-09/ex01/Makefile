CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -DEBUG=0
NAME		=	RPN
HEADER		=	RPN.hpp
FILES		=	main.cpp RPN.cpp

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