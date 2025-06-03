CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME		=	animal
HEADER		=	Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
FILES		=	Animal.cpp main.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

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