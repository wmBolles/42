/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:19:01 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/13 10:55:57 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int nb)
{
	int	count;

	count = (nb <= 0);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ascii;
	int			len;
	long		digit;

	digit = n;
	len = count_digit(digit);
	ascii = malloc(len + 1);
	if (!ascii)
		return (NULL);
	ascii[len--] = '\0';
	if (digit < 0)
	{
		ascii[0] = '-';
		digit = -digit;
	}
	if (digit == 0)
		ascii[0] = '0';
	while (digit > 0)
	{
		ascii[len--] = (digit % 10) + '0';
		digit /= 10;
	}
	return (ascii);
}
