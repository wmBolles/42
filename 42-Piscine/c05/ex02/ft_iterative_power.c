/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:46:24 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/24 20:04:38 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		pr;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (0x1);
	pr = nb;
	while (0b1 < power)
	{
		nb *= pr;
		power -= 2 >> 1;
	}
	return (nb);
}
