/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:09 by wabolles          #+#    #+#             */
/*   Updated: 2024/03/13 17:36:00 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	check_pid(char *pid)
{
	int		index;

	index = 0;
	if (pid[index] == '\0')
		return (_FAILURE_);
	while (pid[index])
	{
		if (!(pid[index] >= '0' && pid[index] <= '9'))
			return (_FAILURE_);
		index++;
	}
	return (_SUCCSESS_);
}

int	ft_atoi(char *av1)
{
	int		pid;

	pid = 0;
	while (*av1 >= '0' && *av1 <= '9')
	{
		pid *= 10;
		pid += *av1 - 48;
		av1++;
	}
	return (pid);
}

int	send_bits(int pid, char byte)
{
	int		index;

	index = 7;
	while (index >= 0)
	{
		if (((byte >> index) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error sending SIGUSR1 ! \n");
				return (_FAILURE_);
			}
		}
		else if (((byte >> index) & 1) == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending SIGUSR2 ! \n");
				return (_FAILURE_);
			}
		}
		usleep(505);
		index--;
	}
	return (_SUCCSESS_);
}

int	send_bytes(int pid, char *msg)
{
	int		index;

	if (pid <= 0 || pid > 99998)
	{
		ft_printf("Bad Process Id ! \n");
		return (_FAILURE_);
	}
	index = 0;
	while (msg[index])
	{
		if (send_bits(pid, msg[index]))
			return (_FAILURE_);
		index++;
	}
	if (send_bits(pid, '\0'))
		return (_FAILURE_);
	return (_SUCCSESS_);
}

int	main(int ac, char *av[])
{
	signal(SIGUSR1, complete);
	if (ac == 3)
	{
		if (check_pid(av[1]))
		{
			ft_printf("Bad Process Id !\n");
			return (_FAILURE_);
		}
		else
		{
			if (send_bytes(ft_atoi(av[1]), av[2]))
				return (_FAILURE_);
			return (_SUCCSESS_);
		}
	}
	else
	{
		ft_printf("Enter The Process Id Followed By Message !\n");
		return (_FAILURE_);
	}
}
