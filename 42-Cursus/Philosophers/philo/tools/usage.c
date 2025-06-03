/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:35:02 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 12:02:45 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int
	err(char *error)
{
	write(2, "\n", 1);
	while (*error)
		write(2, error++, 1);
	write(2, "\n", 1);
	return (FAILURE);
}

static
	void	ft_putstr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

int
	usage_display(void)
{
	ft_putstr("\033[31m\n");
	ft_putstr("Please enter 5 arguments after ./philo\n");
	ft_putstr("\033[33m\n");
	ft_putstr("number_of_philosophers\n");
	ft_putstr("time_to_die\n");
	ft_putstr("time_to_eat\n");
	ft_putstr("time_to_sleep\n");
	ft_putstr("[number_of_times_each_philosopher_must_eat]\n");
	ft_putstr("\033[0m\n");
	return (FAILURE);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		total;

	gettimeofday(&time, NULL);
	total = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (total);
}

long long	diff(long long past, long long now)
{
	return (now - past);
}
