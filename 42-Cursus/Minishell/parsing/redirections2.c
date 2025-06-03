/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:06:24 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 15:21:57 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_output(t_command *cmd, int i)
{
	int		fd;
	int		j;

	fd = 0;
	if (cmd->command[i + 1])
		fd = open(cmd->command[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		j = 0;
		while (cmd->command[j])
			(1) && (cmd->command[j] = NULL, j++);
		(1) && (perror("open"), exit_status(1, 1));
		return ;
	}
	(1) && (cmd->fd_out = fd, j = i);
	if (cmd->command[j + 1])
	{
		while (cmd->command[j + 2])
			(1) && (cmd->command[j] = cmd->command[j + 2], j++);
		(1) && (cmd->command[j] = NULL, cmd->command[j + 1] = NULL);
	}
	if (exit_status(0, 0) != 1)
		exit_status(0, 1);
}

void	ft_input(t_command *cmd, int i)
{
	int		fd;
	int		j;

	fd = open(cmd->command[i + 1], O_RDONLY, 0644);
	if (fd == -1)
	{
		j = 0;
		while (cmd->command[j])
			(1) && (cmd->command[j] = NULL, j++);
		(1) && (perror("open"), exit_status(1, 1));
		return ;
	}
	(1) && (cmd->fd_in = fd, j = i);
	if (cmd->command[j + 1])
	{
		while (cmd->command[j + 2])
			(1) && (cmd->command[j] = cmd->command[j + 2], j++);
		(1) && (cmd->command[j] = NULL, cmd->command[j + 1] = NULL);
	}
	if (exit_status(0, 0) != 1)
		exit_status(0, 1);
}

void	ft_append(t_command *cmd, int i)
{
	int		fd;
	int		j;

	fd = open(cmd->command[i + 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
	{
		j = 0;
		while (cmd->command[j])
			(1) && (cmd->command[j] = NULL, j++);
		(1) && (perror("open"), exit_status(1, 1));
		return ;
	}
	(1) && (cmd->fd_out = fd, j = i);
	if (cmd->command[j + 1])
	{
		while (cmd->command[j + 2])
			(1) && (cmd->command[j] = cmd->command[j + 2], j++);
		(1) && (cmd->command[j] = NULL, cmd->command[j + 1] = NULL);
	}
	if (exit_status(0, 0) != 1)
		exit_status(0, 1);
}

void	norm_red2(t_red *d, t_command *cmd, t_env *env)
{
	if (d->i + 1 < d->len && cmd->command[d->i + 1]
		&& cmd->command[d->i + 1][0] != '\0')
	{
		unlink("tmp.txt");
		d->fd_write = open("tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		d->fd_read = open("tmp.txt", O_RDONLY, 0644);
		unlink("tmp.txt");
		ft_heredoc(cmd, d->i, d->fd_write, env);
		cmd->fd_in = d->fd_read;
		d->j = d->i;
		while (cmd->command[d->j + 2])
		{
			cmd->command[d->j] = cmd->command[d->j + 2];
			d->j++;
		}
		cmd->command[d->j] = NULL;
		cmd->command[d->j + 1] = NULL;
		unlink("tmp.txt");
		d->len = 0;
		while (cmd->command[d->len])
			d->len++;
	}
	else
		d->i++;
}
