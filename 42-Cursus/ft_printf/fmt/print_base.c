/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 05:27:10 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/29 08:01:52 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	print_base16_u(unsigned int _)
{
	int	count;

	count = ~(-1);
	if (_ >= 16)
		count += print_base16_u(_ / 16);
	count += print_char(_BASE_16_[_ % 16]);
	return (count);
}

int	print_base16_l(unsigned int _)
{
	int	count;

	count = 0x0;
	if (_ >= 16)
		count += print_base16_l(_ / 16);
	count += print_char(_BASE_16[_ % 16]);
	return (count);
}
