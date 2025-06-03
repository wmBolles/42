/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:04:28 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 21:27:18 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int
	is_not_valid(char *argument)
{
	int			index;

	index = 0;
	if (argument[index] == '\0')
		return (err("\033[31mempty argument !\n\033[0m"));
	while (argument[index] == '-' || argument[index] == '+')
		index++;
	if (argument[index] == ' ' || argument[index] == '\0')
		return (err("\033[31margument is not valid !\033[0m\n"));
	while (argument[index])
	{
		if (!(argument[index] >= '0' && argument[index] <= '9'))
			return (err("\033[31margument is not valid !\033[0m\n"));
		index++;
	}
	return (SUCCESS);
}

static int
	is_not_valid_as_number(char *argument)
{
	ssize_t		number;

	number = ft_atoi(argument);
	if (number == -7)
		return (err("\033[31mOverFlow Detected !\033[0m\n"));
	if (number < -2147483648)
		return (err("\033[31mnumber < MIN_INT\033[0m\n"));
	else if (number > 2147483647)
		return (err("\033[31mnumber > MAX_INT\033[0m\n"));
	else if (number == 0)
		return (err("\033[31mnumber = 0\033[0m\n"));
	else if (number < 0)
		return (err("\033[31mnumber < 0\033[0m\n"));
	return (SUCCESS);
}

static int
	set_table(int ac, char **av, t_table *table)
{
	char	*error;

	error = "\033[31mDo not test with more than 200 philosophers.\033[0m\n";
	table->n_philo = ft_atoi(av[1]);
	table->t_to_die = ft_atoi(av[2]);
	table->t_to_eat = ft_atoi(av[3]);
	table->t_to_sleep = ft_atoi(av[4]);
	if (table->n_philo > 200)
		return (err(error));
	if (table->t_to_die < 60 || table->t_to_eat < 60 || table->t_to_sleep < 60)
		return (err("\033[31mDon't test with values lower than 60 ms.\n"));
	if (ac == 6)
		table->max_meals = ft_atoi(av[5]);
	else
		table->max_meals = -FAILURE;
	if (set_mutex(table))
		return (err("\033[31mMutex Error !\033[0m\n"));
	set_philos(table);
	return (SUCCESS);
}

int
	parse_args(int ac, char **av, t_table *table)
{
	int		index;

	if (ac < 5 || ac > 6)
		return (usage_display());
	index = 1;
	while (index < ac)
	{
		if (is_not_valid(av[index]))
			return (FAILURE);
		if (is_not_valid_as_number(av[index]))
			return (FAILURE);
		index++;
	}
	if (set_table(ac, av, table))
		return (FAILURE);
	return (SUCCESS);
}
