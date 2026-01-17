/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:52:21 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 21:16:58 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int			sign;
	long		number;
	int			index;

	index = 0;
	while (str[index] && is_spaces(str[index]))
		index++;
	sign = 1;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			sign = -sign;
	number = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = (number * 10) + (str[index] - 48);
		if (number > 2147483648 && sign == -1)
			exit_err();
		else if (number > 2147483647 && sign == 1)
			exit_err();
		index++;
	}
	return (number * sign);
}
