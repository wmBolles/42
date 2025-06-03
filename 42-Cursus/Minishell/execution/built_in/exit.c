/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:32:55 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 09:44:18 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

long long	ft_valid_arg(char *str, int *valid)
{
	short				s;
	unsigned long long	n;
	unsigned long long	tmp;

	if (!str)
		return (*valid = 0, 0);
	(1) && (s = 1, n = 0, *valid = 0);
	while (str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '+')
		(str)++;
	else if (*str == '-')
		(1) && (s *= -1, (str)++);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		(1) && (tmp = n, n = n * 10 + *str - '0');
		if (tmp > n || (n > LLONG_MAX && s == 1)
			|| (s == -1 && (long long)n * s < LLONG_MIN))
			return (0);
		str++;
	}
	return (*valid = 1, s * n);
}

void	ft_exit(t_command *exec, char **arg)
{
	int			valid;
	long long	n;

	valid = 1;
	(void)exec;
	if (!arg || !arg[1])
		exit(exit_status(0, 0));
	n = ft_valid_arg(arg[1], &valid);
	if (!valid)
	{
		ft_error(ft_strjoin("exit: ", arg[1]), ": numeric argument required");
		exit(255);
	}
	if (arg[2])
	{
		ft_error("exit: ", "too many arguments");
		exit_status(1, 1);
		return ;
	}
	exit(n);
}
