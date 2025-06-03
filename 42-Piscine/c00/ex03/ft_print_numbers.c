/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:41:40 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/12 15:21:53 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int		nb;

	nb = 0;
	while (nb <= 9)
		ft_putchar(nb++ + 48);
}
