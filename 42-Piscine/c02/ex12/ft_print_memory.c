/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:10:47 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/21 00:29:02 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define HEXA "0123456789abcdef"

typedef unsigned char	t_byte;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_string(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			ft_putchar('.');
		else
			ft_putchar(*str);
		str++;
	}
}

void	print_hexa(char	*addr, int size)
{
	int		i;

	i = 0;
	while (addr[i] && i < size)
	{
		ft_putchar(HEXA[addr[i] / 16]);
		ft_putchar(HEXA[addr[i] % 16]);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}

void	print_address(void *addr)
{
	t_byte	*ptr_byte;
	int		i;

	ptr_byte = (t_byte *)&addr;
	i = 7;
	while (i >= 0)
	{
		ft_putchar(HEXA[ptr_byte[i] / 16]);
		ft_putchar(HEXA[ptr_byte[i] % 16]);
		i--;
	}
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	print_address(addr);
	print_hexa(addr, size);
	put_string(addr);
	ft_putchar('\n');
	return (addr);
}
