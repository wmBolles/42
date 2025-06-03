/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:49:24 by wabolles          #+#    #+#             */
/*   Updated: 2023/08/02 03:42:12 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		check_the_base(char *base);
int		ft_strlen(char *base_len);
int		check_the_number(int nbr);

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	char			arr[256];
	int				i;

	nb = 0;
	if (!(check_the_base(base)))
		return ;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	nb = check_the_number(nbr);
	i = 0;
	while (nb)
	{
		arr[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	while (i--)
		ft_putchar(arr[i]);
}

int	check_the_number(int nbr)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	return (nb);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_the_base(char *base)
{
	int		i;
	int		j;

	if (*base == '\0' || ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *base_len)
{
	int		i;

	i = 0;
	while (base_len[i])
		i++;
	return (i);
}
