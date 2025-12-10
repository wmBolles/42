CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -D DEBUG=0
NAME		=	Form
HEADER		=	Bureaucrat.hpp Form.hpp
FILES		=	Form.cpp Bureaucrat.cpp  main.cpp  

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