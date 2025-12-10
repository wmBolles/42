CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -D DEBUG=0
NAME		=	btc
HEADER		=	BitcoinExchange.hpp
FILES		=	main.cpp BitcoinExchange.cpp

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