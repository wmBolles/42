/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:34:57 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 21:33:51 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void
	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left]);
	output(philo->table, "has taken a fork", philo->pid);
	pthread_mutex_lock(&philo->table->forks[philo->right]);
	output(philo->table, "has taken a fork", philo->pid);
	output(philo->table, "is eating", philo->pid);
	pthread_mutex_lock(&philo->table->check);
	philo->last_meal = get_time();
	(philo->nmeals)++;
	pthread_mutex_unlock(&philo->table->check);
	exact_sleep(philo->table->t_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->right]);
	pthread_mutex_unlock(&philo->table->forks[philo->left]);
}

void
	*routine(void	*philo)
{
	t_philo		*ph;
	t_table		*table;

	ph = (t_philo *)philo;
	if (!philo)
		return (NULL);
	table = ph->table;
	if (ph->pid % 2 != 0)
		usleep(table->t_to_eat);
	while (TRUE)
	{
		eating(philo);
		output(table, "is sleeping", ph->pid);
		exact_sleep(table->t_to_sleep);
		output(table, "is thinking", ph->pid);
	}
	return (NULL);
}

int
	is_ate(t_table *table, t_philo *philo)
{
	int		index;
	int		how_much;

	index = 0;
	how_much = index;
	while (index < table->n_philo && table->max_meals != -FAILURE)
	{
		pthread_mutex_lock(&table->check);
		if (philo[index].nmeals >= table->max_meals)
			how_much++;
		pthread_mutex_unlock(&table->check);
		index++;
	}
	if (how_much == table->n_philo)
		return (FAILURE);
	return (SUCCESS);
}

void	azrael(t_table *table, t_philo *philo)
{
	int		index;

	while (TRUE)
	{
		index = SUCCESS;
		while (index < table->n_philo)
		{
			pthread_mutex_lock(&table->check);
			if (diff(philo->last_meal, get_time()) > table->t_to_die)
			{
				pthread_mutex_lock(&table->printing);
				printf("%lli", get_time() - table->first);
				printf(" %i %s\n", index + 1, "died");
				return ;
			}
			pthread_mutex_unlock(&table->check);
			usleep(50);
			index++;
		}
		if (table->max_meals != 0 && is_ate(table, philo))
			break ;
	}
}

int
	simulation(t_table *table)
{
	t_philo		*philo;
	int			index;

	table->first = get_time();
	philo = table->philos;
	index = SUCCESS;
	while (index < table->n_philo)
	{
		if (pthread_create(&philo[index].tid, NULL, routine, &philo[index]))
			return (err("\033[31mCreating thread Error !\033[0m\n"));
		pthread_detach(philo[index].tid);
		pthread_mutex_lock(&table->check);
		philo[index].last_meal = get_time();
		pthread_mutex_unlock(&table->check);
		index++;
	}
	azrael(table, philo);
	quit_simualtion(table);
	return (SUCCESS);
}
