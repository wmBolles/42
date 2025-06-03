/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:31:08 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 21:24:25 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int
	main(int ac, char *av[])
{
	t_table		table;

	if (parse_args(ac, av, &table))
		return (FAILURE);
	if (table.n_philo == 1)
	{
		table.first = get_time();
		output(&table, "has taken a fork", table.philos[0].pid);
		exact_sleep(table.t_to_die);
		printf("%lld ", get_time() - table.first);
		printf("%d died\n", table.philos[0].pid + 1);
		return (SUCCESS);
	}
	if (simulation(&table))
		return (FAILURE);
	return (SUCCESS);
}
