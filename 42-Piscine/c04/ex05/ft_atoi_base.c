/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:50:17 by wabolles          #+#    #+#             */
/*   Updated: 2023/08/01 16:54:49 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_twice(char c, char *base);
int		ft_strlen(char *str);
int		check_the_base(char *base);

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		nb;

	if (!check_the_base(base))
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb *= ft_strlen(base);
		nb += *str - 48;
		str++;
	}
	return (sign * nb);
}

int	check_twice(char c, char *base)
{
	int		check_twice;

	check_twice = 0;
	while (*base)
	{
		if (c == *base)
		{
			check_twice++;
			if (check_twice == 2)
				return (0);
		}
		base++;
	}
	return (1);
}

int	check_the_base(char *base)
{
	int		i;

	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (!check_twice(base[i], base))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
