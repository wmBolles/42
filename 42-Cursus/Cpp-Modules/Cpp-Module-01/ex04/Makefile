CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -c -std=c++98
NAME		=	search_and_replace
FILE		=	main.cpp
OBJC		=	$(FILE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CPP) $(FILE) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $<

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean