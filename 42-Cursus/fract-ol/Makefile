# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 08:59:54 by wabolles          #+#    #+#              #
#    Updated: 2024/08/24 17:15:23 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Assets
CC 		=	cc
CFLAGS	=	-c -Wall -Wextra -Werror -I./inc
OPENGL	=	-framework OpenGL
APPKIT	=	-framework AppKit
FAST	=	-O3
LINK	=	-lmlx
HEADER	=	./inc/headers.h
NAME	=	fractol

# MLX_FILES = mlx/mlx_clear_window.c mlx/mlx_expose_hook.c mlx/mlx_get_data_addr.c \
#     		mlx/mlx_int_do_nothing.c mlx/mlx_int_str_to_wordtab.c mlx/mlx_loop.c \
# 			mlx/mlx_new_image.c            mlx/mlx_rgb.c          mlx/mlx_xpm.c  \
# 			mlx/mlx_destroy_display.c  mlx/mlx_ext_randr.c        mlx/mlx_hook.c \
# 			mlx/mlx_int_get_visual.c mlx/mlx_int_wait_first_expose.c  			 \
# 			mlx/mlx_loop_hook.c   mlx/mlx_new_window.c     mlx/mlx_screen_size.c \
# 			mlx/mlx_destroy_image.c    mlx/mlx_flush_event.c      mlx/mlx_init.c \
# 			mlx/mlx_int_param_event.c mlx/mlx_key_hook.c    mlx/mlx_mouse.c      \
# 			mlx/mlx_pixel_put.c            mlx/mlx_set_font.c 					 \
# 			mlx/mlx_destroy_window.c   mlx/mlx_get_color_value.c  				 \
# 			mlx/mlx_int_anti_resize_win.c  mlx/mlx_int_set_win_event_mask.c      \
# 			mlx/mlx_lib_xpm.c                mlx/mlx_mouse_hook.c  				 \
# 			mlx/mlx_put_image_to_window.c  mlx/mlx_string_put.c

# PRINTF FILES
PRINTF_FILES = ft_printf/fmt/print_addr.c 	\
		       ft_printf/fmt/print_base.c 	\
			   ft_printf/fmt/print_cs.c   	\
			   ft_printf/fmt/print_nbrs.c 	\
		       ft_printf/fmt/which_format.c \
		       ft_printf/ft_printf.c

# FRACTOL_FILES
TOOLS = tools/tools.c tools/usage_display.c tools/tools2.c \
		tools/events.c
FRACTALS = fractals/mandelbrot.c fractals/julia.c
FILES = fract-ol.c $(PRINTF_FILES) $(TOOLS) $(FRACTALS)
OBJ = $(FILES:.c=.o)

#Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LINK) $(OBJ) $(APPKIT) $(OPENGL) -o $(NAME)

./%.o: ./%.c $(HEADER)
	$(CC) $(FAST) $(CFLAGS) $< -o $@
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)
	
re:	fclean all

.PHONY: clean