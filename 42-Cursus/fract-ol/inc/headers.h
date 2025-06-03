/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:20:26 by wabolles          #+#    #+#             */
/*   Updated: 2024/08/24 17:16:14 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

// Includes
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

// Data
enum e_vars
{
	ESC = 53,
	SUCCESS = 0,
	FAILURE = 1,
	WIDTH = 600,
	HEIGHT = 600,
	MAX_ITER = 100,
	ZOOM_IN = 5,
	ZOOM_OUT = 4
};

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_xdata
{
	void	*connect;
	void	*win;
	void	*img_ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		endian;
	int		size_len;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_xdata;

// Printf Files
# define _FD_OUT 1
# define _BASE_16 "0123456789abcdef"
# define _BASE_16_ "0123456789ABCDEF"

int			print_char(int c);
int			print_nbr(int nbr);
int			print_string(char *buff);
int			print_address(void *addr);
int			print_uint(unsigned int nbr);
int			ft_printf(const char *s, ...);
int			print_base16_u(unsigned int _);
int			print_base16_l(unsigned int _);
int			which_format(char fmt, va_list ellipsis);

//	Fractol Files
double		scaling(double point, double new_min, double new_max);
int			mousezoomlistiner_julia(int button, int x, int y, t_xdata *fract);
int			mousezoomlistiner(int button, int x, int y, t_xdata *fract);
void		pixel_img_put(t_xdata *data, int x, int y, int color);
int			keyeventlistiner(int keycode, t_xdata *fract);
t_complex	add_complex(t_complex z1, t_complex z2);
void		events_listiner_julia(t_xdata *fract);
int			julia(char *name, double x, double y);
int			mouseeventlistiner(t_xdata *fract);
int			_rgb(int op, int r, int g, int b);
void		events_listiner(t_xdata *fract);
void		rendering_julia(t_xdata *fract);
int			ft_strcmp(char *s1, char *s2);
t_complex	square_complex(t_complex z);
void		rendering(t_xdata *fract);
int			mandelbrot(char *name);
int			usage_display(void);
int			is_double(char *d);
double		atodouble(char *s);

#endif