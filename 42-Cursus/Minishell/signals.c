/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:11:46 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/30 08:43:33 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_her(int num)
{
	(void)num;
	exit_status(1, 1);
	close(0);
}

void	ft_signal_c(int num)
{
	if (!g_stat)
	{
		if (num == SIGINT)
		{
			exit_status(1, 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			ft_putstr_fd("\n", 1);
			rl_redisplay();
		}
	}
}

void	ft_signal(void)
{
	signal(SIGQUIT, ft_signal_c);
	signal(SIGINT, ft_signal_c);
}
