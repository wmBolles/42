/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:31:34 by wabolles          #+#    #+#             */
/*   Updated: 2024/03/13 17:14:45 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_printf(const char *s, ...)
{
	va_list		ellipsis;
	int			__;

	if (write(_FD_OUT, "chi haja", 0) == -1)
		return (-1);
	va_start(ellipsis, s);
	__ = 0b00000000000000;
	while (*s)
	{
		if (*s == '%')
		{
			if (!((*(s + 1) == ' ') || *(s + 1) == '\0'))
				__ += which_format(*(++s), ellipsis);
		}
		else
			__ += write(1, s, 1);
		s += (2 >> 1);
	}
	va_end(ellipsis);
	return (__);
}
