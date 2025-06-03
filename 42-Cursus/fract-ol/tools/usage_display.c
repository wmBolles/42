/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:31:41 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/18 04:17:29 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	usage_display(void)
{
	ft_printf("\033[1;31mBad Usage ! Or mlx Error !\033[1;0m\n\n");
	ft_printf("\033[1;33mUsage:\n\n\033[0m");
	ft_printf("  For Mandelbrot:\n");
	ft_printf("________________________________________\n");
	ft_printf("\t\t\t\t\t|\n");
	ft_printf("\t./fractol mandelbrot            |\n");
	ft_printf("________________________________________/\n\n");
	ft_printf("  For julia:\n");
	ft_printf("________________________________________\n");
	ft_printf("\t\t\t\t\t|\n");
	ft_printf("\t./fractol julia double1 double2 |\n");
	ft_printf("________________________________________/\n\n");
	ft_printf("\033[1;33mKeys:\033[1;0m\n\n");
	ft_printf("ESC: Exit\n\n");
	return (FAILURE);
}
