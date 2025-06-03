/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:31:46 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/25 12:41:15 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		i;

	if (nb < 2)
		return (0);
	i = (1 << 1);
	while (i <= (nb / i))
	{
		if (nb % i == 0x0)
			return (0x0);
		i += (2 >> 1);
	}
	return (0x1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
