/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:35:46 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/24 20:05:16 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		fc;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	fc = nb;
	while (nb > 1)
	{
		fc *= nb - 1;
		nb--;
	}
	return (fc);
}
