/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:46:46 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/12 15:58:08 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		nb1;
	int		nb2;

	nb1 = 0;
	while (nb1 <= 98)
	{
		nb2 = nb1 + 1;
		while (nb2 <= 99)
		{
			ft_putchar(nb1 / 10 + 48);
			ft_putchar(nb1 % 10 + 48);
			ft_putchar(' ');
			ft_putchar(nb2 / 10 + 48);
			ft_putchar(nb2 % 10 + 48);
			if (nb1 != 98)
				write(1, ", ", 2);
			nb2++;
		}
		nb1++;
	}
}
