/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:02:56 by wabolles          #+#    #+#             */
/*   Updated: 2024/03/13 15:41:13 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_intro(int pid)
{
	ft_printf("\n\033[1;33m");
	ft_printf("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_printf("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_printf("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_printf("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_printf("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_printf("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
	ft_printf("Process ID: \033[1;34m%d\033[1;30m\t", pid);
	ft_printf("     Created By: wabolles\n\n>> \033[1;0m");
}

void	handle_signal(int sig, siginfo_t *info,
void __attribute__ ((unused)) *unused)
{
	static char		byte;
	static int		pid;
	static int		bit;

	if (info->si_pid != pid)
	{
		byte = 0;
		bit = 0;
		pid = info->si_pid;
	}
	bit++;
	if (sig == SIGUSR1)
		byte++;
	if (bit <= 7)
		byte <<= 1;
	else
	{
		ft_printf("%c", byte);
		byte = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	signal.__sigaction_u.__sa_sigaction = &handle_signal;
	signal.sa_flags = SA_SIGINFO;
	print_intro(getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &signal, NULL) == -1)
		{
			ft_printf("Sigaction Sigusr1 Error!\n");
			return (1);
		}
		if (sigaction(SIGUSR2, &signal, NULL) == -1)
		{
			ft_printf("Sigaction Sigusr2 Error!\n");
			return (1);
		}
		pause();
	}
}
