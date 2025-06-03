/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:21:52 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/20 14:46:17 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int ac, char *av[])
{
	if (HEIGHT < 1 || WIDTH < 1)
		return (usage_display());
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		if (mandelbrot(av[1]))
			return (usage_display());
		return (SUCCESS);
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia")
		&& !is_double(av[2]) && !is_double(av[3]))
	{
		if (julia(av[1], atodouble(av[2]), atodouble(av[3])))
			return (usage_display());
		return (SUCCESS);
	}
	else
		return (usage_display());
}
