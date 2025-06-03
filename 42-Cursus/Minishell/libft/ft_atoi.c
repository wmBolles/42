/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:01:50 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/22 04:04:37 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi(const char *str)
{
	int				sign;
	long int		number;
	long int		nbr;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = number * 10 + (*str - 48);
		if (nbr < number && sign == -1)
			return (0);
		if (nbr < number && sign == 1)
			return (-1);
		number = nbr;
		str++;
	}
	return (sign * number);
}
