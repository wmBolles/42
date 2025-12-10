CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -D DEBUG=1
NAME		=	PmergeMe
HEADER		=	PmergeMe.hpp
SRCS		=	main.cpp PmergeMe.cpp MergeSort.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean