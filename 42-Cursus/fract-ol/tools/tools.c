/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:28:42 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/19 15:26:20 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	return (s1[index] - s2[index]);
}

int	is_double(char *d)
{
	int		index;
	int		check_dup;

	index = 0;
	check_dup = 0;
	if (d[index] == '.')
		return (FAILURE);
	while (d[index] == '+' || d[index] == '-')
		index++;
	if (d[index] == '.')
		return (FAILURE);
	while (d[index])
	{
		if (!((d[index] >= '0' && d[index] <= '9') || d[index] == '.'))
			return (FAILURE);
		if (d[index] == '.')
			check_dup++;
		index++;
	}
	if (check_dup > 1 || d[index - 1] == '.')
		return (FAILURE);
	return (SUCCESS);
}

void	pixel_img_put(t_xdata *data, int x, int y, int color)
{
	int	point;

	point = (y * data->size_len) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->data_addr + point) = color;
}

double	scaling(double point, double new_min, double new_max)
{
	return ((new_max - new_min) * ((point) / WIDTH) + new_min);
}
