/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 05:17:12 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/19 15:14:03 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

double	atodouble(char *s)
{
	long		befor_point;
	double		after_point;
	double		pow;
	int			sign;

	befor_point = 0;
	after_point = 0;
	pow = 1;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		befor_point = befor_point * 10 + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		after_point = after_point + (*s++ - 48) * pow;
	}
	return ((befor_point + after_point) * sign);
}

int	mousezoomlistiner_julia(int button, int x, int y, t_xdata *fract)
{
	(void)x;
	(void)y;
	mlx_clear_window(fract->connect, fract->win);
	if (button == ZOOM_IN)
		fract->zoom *= 2;
	else if (button == ZOOM_OUT)
		fract->zoom /= 2;
	rendering_julia(fract);
	return (SUCCESS);
}
