CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME		=	violence
HEADER		=	Weapon.hpp HumanA.hpp HumanB.hpp 
FILES		=	HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
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