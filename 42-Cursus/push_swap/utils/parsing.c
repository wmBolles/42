/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:21:47 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 22:55:24 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **a, t_node **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "22\n", 3);
}

int	check_arg(char *arg)
{
	int		index;

	index = 0x0;
	if (arg[index] >= 9 && arg[index] <= 13)
		return (0);
	while (arg[index])
	{
		if (arg[index] >= '0' && arg[index] <= '9')
			return (1);
		index++;
	}
	return (0);
}

char	*join_args(int ac, char *av[])
{
	int		index;
	char	*arg1;
	char	*arg;
	char	*temp;

	arg = "";
	index = 1;
	while (index < ac)
	{
		temp = arg;
		if (check_arg(av[index]))
		{
			arg1 = ft_strjoin(arg, av[index]);
			arg = ft_strjoin(arg1, " ");
			free(arg1);
		}
		else
			exit_err();
		if (index > 1)
			free(temp);
		index++;
	}
	return (arg);
}
