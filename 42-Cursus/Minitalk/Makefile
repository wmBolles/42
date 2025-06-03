# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 14:40:01 by wabolles          #+#    #+#              #
#    Updated: 2024/03/13 17:16:23 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
HEADER = includes/minitalk.h

#	PRINTF

PRINTF_FILES = printf/fmt/print_addr.c \
			printf/fmt/print_base.c \
			printf/fmt/print_cs.c   \
			printf/fmt/print_nbrs.c \
			printf/fmt/which_format.c \
			printf/ft_printf.c

PRINTF_OBJC = $(PRINTF_FILES:.c=.o) 

#	MINITALK

SERVER = server
CLIENT = client

SERVER_BNS = server_bonus
CLIENT_BNS = client_bonus

SRV = mandatory/server.c $(PRINTF_FILES)
CLT = mandatory/client.c $(PRINTF_FILES)

SRV_OBJ = $(SRV:.c=.o)
CLT_OBJ = $(CLT:.c=.o)

SRV_BNS = bonus/complete.c bonus/advanced_server.c $(PRINTF_FILES)
CLT_BNS = bonus/complete.c bonus/advanced_client.c $(PRINTF_FILES)

SRV_BNS_OBJ = $(SRV_BNS:.c=.o)
CLT_BNS_OBJ = $(CLT_BNS:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRV_OBJ)
	@$(CC) $(CFLAGS) $(SRV_OBJ) -o $(SERVER)
$(CLIENT): $(CLT_OBJ)
	@$(CC) $(CFLAGS) $(CLT_OBJ) -o $(CLIENT)

$(SERVER_BNS): $(SRV_BNS_OBJ)
	@$(CC) $(CFLAGS) $(SRV_BNS_OBJ) -o $(SERVER_BNS)
$(CLIENT_BNS): $(CLT_BNS_OBJ)
	@$(CC) $(CFLAGS) $(CLT_BNS_OBJ) -o $(CLIENT_BNS)

bonus: $(SERVER_BNS) $(CLIENT_BNS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\033[1;34mCompile C file\033[1;0m"

clean: $(NAME)
	@rm -rf $(SRV_BNS_OBJ) $(CLT_BNS_OBJ) $(SRV_OBJ) $(CLT_OBJ)
	@echo "\033[1;33mClean object files... ✅\033[1;0m"

fclean: clean
	@rm -rf	$(CLIENT) $(SERVER) $(CLIENT_BNS) $(SERVER_BNS)
	@echo "\033[1;33mClean executables... ✅\033[1;0m"

re: fclean all

.PHONY: clean