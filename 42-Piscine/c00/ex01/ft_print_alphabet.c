/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:40:32 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/12 11:18:21 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	a;

	a = 97;
	while (a <= 122)
		ft_putchar(a++);
}
