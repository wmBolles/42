/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:56:44 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/24 23:41:23 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define HEXA "0123456789abcdef"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int	is_no_pr(char c)
{
	if (c < 32 || c > 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	int				i;

	i = 0x0;
	while (str[i])
	{
		c = *str;
		if (is_no_pr(str[i]))
		{
			ft_putchar('\\');
			ft_putchar(HEXA[str[i] / 16]);
			ft_putchar(HEXA[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
