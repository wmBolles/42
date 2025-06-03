/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:41:38 by wabolles          #+#    #+#             */
/*   Updated: 2024/02/17 21:45:05 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	print_char(int c)
{
	return (write(_FD_OUT, &c, 0b0001));
}

int	print_string(char *buff)
{
	int		count;

	count = (1 >> 1);
	if (!buff)
		return (write(1, "(null)", 6));
	while (buff[count])
		count += write(_FD_OUT, &buff[count], 0x1);
	return (count);
}
