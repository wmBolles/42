/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:11:11 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 09:57:00 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_heredoc(t_command *cmd, int i, int fd, t_env *env)
{
	ft_handle_quotes(cmd, i);
	ft_process_input(cmd, i, fd, env);
}

void	norm_red3(t_red *d, t_command *cmd)
{
	if (d->i + 1 < d->len && cmd->command[d->i + 1]
		&& cmd->command[d->i + 1][0] != '\0')
	{
		ft_output(cmd, d->i);
		d->len = 0;
		while (cmd->command[d->len])
			d->len++;
	}
	else
		d->i++;
}

void	norm_red4(t_red *d, t_command *cmd)
{
	if (d->i + 1 < d->len && cmd->command[d->i + 1]
		&& cmd->command[d->i + 1][0] != '\0')
	{
		ft_append(cmd, d->i);
		d->len = 0;
		while (cmd->command[d->len])
			d->len++;
	}
	else
		d->i++;
}

void	norm_red(t_red *d, t_command *cmd, t_env *env)
{
	while (d->i < d->len)
	{
		if (ft_strcmp(cmd->command[d->i], "<<") == 0)
			norm_red2(d, cmd, env);
		else if (ft_strcmp(cmd->command[d->i], "<") == 0)
		{
			if (d->i + 1 < d->len && cmd->command[d->i + 1]
				&& cmd->command[d->i + 1][0] != '\0')
			{
				ft_input(cmd, d->i);
				d->len = 0;
				while (cmd->command[d->len])
					d->len++;
			}
			else
				d->i++;
		}
		else if (ft_strcmp(cmd->command[d->i], ">") == 0)
			norm_red3(d, cmd);
		else if (ft_strcmp(cmd->command[d->i], ">>") == 0)
			norm_red4(d, cmd);
		else
			d->i++;
	}
}

void
	ft_redirection(t_command *cmd, t_env *env)
{
	t_red		d;

	while (cmd)
	{
		(1) && (d.i = 0, d.len = 0);
		while (cmd->command[d.len])
			d.len++;
		d.i = 0;
		norm_red(&d, cmd, env);
		cmd = cmd->next;
	}
}
