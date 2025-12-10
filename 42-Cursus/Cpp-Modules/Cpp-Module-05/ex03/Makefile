CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -D DEBUG=0
NAME		=	Shrubbery
HEADER		=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp  RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
FILES		=	Bureaucrat.cpp  main.cpp AForm.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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