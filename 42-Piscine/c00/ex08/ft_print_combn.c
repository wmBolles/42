/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:07 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:44 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_helper(int *arr, int n, int index, int digit)
{
	int		i;

	if (n == index)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(arr[i] + 48);
			i++;
		}
		if (arr[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	if (digit > 9)
		return ;
	arr[index] = digit;
	ft_helper(arr, n, index + 1, digit + 1);
	ft_helper(arr, n, index, digit + 1);
}

void	ft_print_combn(int n)
{
	int		arr[10];

	if (n > 0 && n < 10)
		ft_helper(arr, n, 0, 0);
}
