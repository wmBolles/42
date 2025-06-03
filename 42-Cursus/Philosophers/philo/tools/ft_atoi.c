/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:51:57 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 19:33:16 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static short
	count_n(ssize_t n)
{
	short	index;

	index = 0;
	if (n < 0)
	{
		n = -n;
		index++;
	}
	while (n > 0)
	{
		n /= 10;
		index++;
	}
	return (index);
}

ssize_t
	ft_atoi(char *s)
{
	ssize_t			number;
	int				index;
	int				sign;

	index = 0;
	while (s[index] == 32 || (s[index] > 9 && s[index] < 13))
		index++;
	sign = 1;
	while (s[index] == '-' || s[index] == '+')
		if (s[index++] == '-')
			sign = -sign;
	number = 0;
	while (s[index] >= '0' && s[index] <= '9')
	{
		number = (number * 10) + (s[index] - 48);
		if (count_n(number) >= count_n(9223372036854775807))
			return (-7);
		index++;
	}
	return (number * sign);
}

void	exact_sleep(long long time)
{
	long long	enter_time;

	enter_time = get_time();
	while (TRUE)
	{
		if (diff(enter_time, get_time()) >= time)
			break ;
		usleep(50);
	}
}

void	output(t_table *table, char *msg, int pid)
{
	pthread_mutex_lock(&table->printing);
	printf("%lli", get_time() - table->first);
	printf(" %i %s\n", pid + 1, msg);
	pthread_mutex_unlock(&table->printing);
	return ;
}

void
	quit_simualtion(t_table *table)
{
	int		index;

	index = SUCCESS;
	while (index < table->n_philo)
	{
		pthread_mutex_destroy(&table->forks[index]);
		index++;
	}
	pthread_mutex_destroy(&table->printing);
	pthread_mutex_destroy(&table->check);
}
