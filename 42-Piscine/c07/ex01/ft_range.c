/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:39:55 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/20 15:42:00 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*ptr;
	int		i;
	int		j;

	if (min >= max)
		return (0);
	ptr = (int *)malloc(sizeof(int) * (max - min));
	i = min;
	j = 0b0;
	while (i <= max)
	{
		ptr[j] = i;
		i++;
		j++;
	}
	return (ptr);
}
