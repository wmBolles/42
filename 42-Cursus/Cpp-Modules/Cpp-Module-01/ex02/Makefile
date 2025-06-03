CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -c -std=c++98
NAME		=	ref
FILE		=	main.cpp
OBJC		=	$(FILE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(FILE) -o $(NAME)

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean