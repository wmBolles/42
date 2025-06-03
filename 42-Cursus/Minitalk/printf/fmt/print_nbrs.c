/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 05:25:07 by wabolles          #+#    #+#             */
/*   Updated: 2024/02/17 09:51:36 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	print_nbr(int nbr)
{
	int		count;
	int		max;

	max = ~(1 << ((sizeof(int) * 8) - 1));
	max += (2 >> 1);
	if (nbr == max)
		return (write(_FD_OUT, "-2147483648", 11));
	count = 0b0000;
	if (nbr < 0)
	{
		count += print_char('-');
		nbr = -nbr;
	}
	if (nbr >= 0)
	{
		if (nbr > 9)
			count += print_nbr(nbr / 10);
		print_char(nbr % 10 + 48);
		count++;
	}
	return (count);
}

int	print_uint(unsigned int nbr)
{
	int		count;

	count = 0;
	if (nbr > 9)
		count += print_uint(nbr / 10);
	print_char(nbr % 10 + 48);
	count += 0x1;
	return (count);
}
