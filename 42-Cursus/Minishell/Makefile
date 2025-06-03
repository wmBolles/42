# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 00:11:37 by wabolles          #+#    #+#              #
#    Updated: 2024/11/30 08:45:10 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror -I./
S = ./.vscode/ft_memcpy.o
SRC = main.c libft/ft_calloc.c libft/ft_isascii.c libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strdup.c \
		libft/ft_strlcat.c libft/ft_strmapi.c libft/ft_strrchr.c libft/ft_tolower.c libft/ft_atoi.c libft/ft_isalnum.c libft/ft_isdigit.c \
		libft/ft_memmove.c libft/ft_putendl_fd.c libft/ft_split.c libft/ft_striteri.c libft/ft_strlcpy.c libft/ft_strncmp.c libft/ft_strtrim.c \
		libft/ft_toupper.c libft/ft_bzero.c libft/ft_isalpha.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_memset.c libft/ft_putnbr_fd.c libft/ft_strchr.c \
		libft/ft_strjoin.c libft/ft_strlen.c libft/ft_substr.c libft/ft_lstnew.c libft/ft_lst_addback.c \
		libft/ft_split_string.c libft/ft_strncpy.c execution/execution.c execution/built_in/echo.c execution/built_in/env.c execution/built_in/exit.c \
		execution/built_in/pwd.c execution/built_in/cd.c execution/execution_utils.c libft/ft_split_quotes.c signals.c execution/execution_pipe.c \
		execution/execution_pipe_utils.c libft/ft_lstsize.c execution/built_in/export.c execution/built_in/env_utils.c execution/built_in/export_utils.c \
		parsing/env.c parsing/attr_func.c  parsing/expansion.c parsing/send_command.c libft/ft_strcat.c libft/ft_strtrok.c execution/built_in/unset.c parsing/redirections.c \
		parsing/expand_heredoc.c parsing/parse1.c libft/split_quotes2.c libft/helper.c libft/strtrock_norm.c \
		parsing/expansion2.c parsing/expansion3.c parsing/send_command2.c parsing/send_command3.c \
		parsing/redirections2.c parsing/redirections3.c execution/built_in/export_utils2.c \
		garbage_collector/gc.c parsing/herdoc.c
		
OBJ = $(SRC:.c=.o)

READLINE_INC = -I$(shell brew --prefix readline)/include
READLINE_LIB = -L$(shell brew --prefix readline)/lib -lreadline

all: $(NAME)

%.o: %.c minishell.h gc.h
	$(CC) $(FLAGS) $(READLINE_INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(S) $(OBJ) $(READLINE_LIB)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean
