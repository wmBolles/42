/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 05:24:33 by wabolles          #+#    #+#             */
/*   Updated: 2024/03/09 22:20:31 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static int	convert_address(unsigned long addr)
{
	int		count;

	count = 0;
	if (addr >= 16)
		count += convert_address(addr / 16);
	count += print_char(_BASE_16[addr % 16]);
	return (count);
}

int	print_address(void *addr)
{
	int			count;

	count = ~(-1);
	if (!addr)
		return (write(_FD_OUT, "0x0", 0x3));
	count += write(_FD_OUT, "0x", 0x2);
	count += convert_address((unsigned long)addr);
	return (count);
}
