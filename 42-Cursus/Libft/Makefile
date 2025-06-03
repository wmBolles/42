# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:59:32 by wabolles          #+#    #+#              #
#    Updated: 2023/11/21 18:38:54 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

BONUS = ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstmap_bonus.c \

FILES = ft_itoa.c ft_memchr.c ft_split.c  ft_strncmp.c \
		ft_atoi.c ft_memcmp.c ft_strchr.c ft_strnstr.c ft_bzero.c \
		ft_memcpy.c ft_strdup.c ft_strrchr.c ft_calloc.c \
		ft_memmove.c ft_striteri.c ft_strtrim.c ft_isalnum.c \
		ft_memset.c ft_strjoin.c ft_substr.c ft_isalpha.c \
		ft_putchar_fd.c ft_strlcat.c ft_tolower.c ft_isascii.c \
		ft_putendl_fd.c ft_strlcpy.c ft_toupper.c ft_isdigit.c \
		ft_putnbr_fd.c ft_strlen.c ft_isprint.c ft_putstr_fd.c ft_strmapi.c \


OBJC = $(FILES:.c=.o)

OBJC_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJC)
	ar rc $(NAME)  $(OBJC)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJC) $(OBJC_BONUS)

fclean: clean
	rm -f $(NAME)

bonus: $(OBJC_BONUS) $(OBJC)
	ar rc $(NAME) $(OBJC_BONUS) $(OBJC)

re: fclean all

.PHONY: all clean fclean bonus re