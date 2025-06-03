/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:53:29 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/19 15:14:21 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	mouseeventlistiner(t_xdata *fract)
{
	mlx_destroy_image(fract->connect, fract->img_ptr);
	mlx_destroy_window(fract->connect, fract->win);
	exit(SUCCESS);
}

int	keyeventlistiner(int keycode, t_xdata *fract)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fract->connect, fract->img_ptr);
		mlx_destroy_window(fract->connect, fract->win);
		exit(SUCCESS);
	}
	return (SUCCESS);
}

int	mousezoomlistiner(int button, int x, int y, t_xdata *fract)
{
	(void)x;
	(void)y;
	mlx_clear_window(fract->connect, fract->win);
	if (button == ZOOM_IN)
		fract->zoom *= 2;
	else if (button == ZOOM_OUT)
		fract->zoom /= 2;
	rendering(fract);
	return (SUCCESS);
}

void	events_listiner(t_xdata *fract)
{
	mlx_key_hook(fract->win, keyeventlistiner, fract);
	mlx_hook(fract->win, 17, 0, mouseeventlistiner, fract);
	mlx_mouse_hook(fract->win, mousezoomlistiner, fract);
}

void	events_listiner_julia(t_xdata *fract)
{
	mlx_key_hook(fract->win, keyeventlistiner, fract);
	mlx_hook(fract->win, 17, 0, mouseeventlistiner, fract);
	mlx_mouse_hook(fract->win, mousezoomlistiner_julia, fract);
}
