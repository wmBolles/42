/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:31:38 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/29 08:30:59 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define _FD_OUT 1
# define _BASE_16 "0123456789abcdef"
# define _BASE_16_ "0123456789ABCDEF"

int	print_char(int c);
int	print_nbr(int nbr);
int	count_digit(int digit);
int	print_string(char *buff);
int	print_address(void *addr);
int	print_uint(unsigned int nbr);
int	ft_printf(const char *s, ...);
int	print_base16_u(unsigned int _);
int	print_base16_l(unsigned int _);
int	which_format(char fmt, va_list ellipsis);

#endif