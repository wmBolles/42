/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:36:54 by wabolles          #+#    #+#             */
/*   Updated: 2024/03/13 15:57:49 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <signal.h>

# define _FD_OUT 1
# define _BASE_16 "0123456789abcdef"
# define _BASE_16_ "0123456789ABCDEF"
# define _FAILURE_ 1
# define _SUCCSESS_ 0

int				print_char(int c);
int				ft_atoi(char *av1);
int				print_nbr(int nbr);
int				count_digit(int digit);
int				print_string(char *buff);
int				print_address(void *addr);
int				print_uint(unsigned int nbr);
int				ft_printf(const char *s, ...);
int				print_base16_u(unsigned int _);
int				print_base16_l(unsigned int _);
int				which_format(char fmt, va_list ellipsis);
void			print_intro(int pid);
void			complete(int __attribute__ ((unused)) pid);

#endif