/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 05:00:53 by wabolles          #+#    #+#             */
/*   Updated: 2024/02/17 09:51:16 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	which_format(char fmt, va_list ellipsis)
{
	int		_;

	_ = 0;
	if (fmt == 'c')
		_ += print_char(va_arg(ellipsis, int));
	else if (fmt == '%')
		_ += write(_FD_OUT, "%", 0x1);
	else if (fmt == 's')
		_ += print_string(va_arg(ellipsis, char *));
	else if (fmt == 'd')
		_ += print_nbr(va_arg(ellipsis, int));
	else if (fmt == 'i')
		_ += print_nbr(va_arg(ellipsis, int));
	else if (fmt == 'u')
		_ += print_uint(va_arg(ellipsis, int));
	else if (fmt == 'X')
		_ += print_base16_u(va_arg(ellipsis, int));
	else if (fmt == 'x')
		_ += print_base16_l(va_arg(ellipsis, int));
	else if (fmt == 'p')
		_ += print_address(va_arg(ellipsis, void *));
	else
		_ += write(_FD_OUT, &fmt, 1);
	return (_);
}
