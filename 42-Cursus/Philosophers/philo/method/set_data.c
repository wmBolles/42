/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:16:58 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 15:23:14 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int
	set_mutex(t_table *table)
{
	int		index;

	index = 0;
	while (index < table->n_philo)
	{
		if (pthread_mutex_init(&table->forks[index], NULL))
			return (FAILURE);
		index++;
	}
	if (pthread_mutex_init(&table->check, NULL))
		return (FAILURE);
	if (pthread_mutex_init(&table->printing, NULL))
		return (FAILURE);
	return (SUCCESS);
}

void
	set_philos(t_table *table)
{
	int		index;

	index = SUCCESS;
	while (index < table->n_philo)
	{
		table->philos[index].pid = index;
		table->philos[index].nmeals = 0;
		table->philos[index].left = index;
		table->philos[index].right = (index + 1) % table->n_philo;
		table->philos[index].last_meal = 0;
		table->philos[index].table = table;
		index++;
	}
}
