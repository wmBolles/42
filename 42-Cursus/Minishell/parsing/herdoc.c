/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:56:03 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 15:38:32 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_handle_quotes_norm(t_command *cmd, int i, char *tmp, int c)
{
	tmp[c] = 0;
	free(cmd->command[i + 1]);
	cmd->command[i + 1] = ft_strdup(tmp);
	free(tmp);
}

void
	ft_handle_quotes(t_command *cmd, int i)
{
	char	quote;
	int		k;
	int		c;
	char	*tmp;

	k = 0;
	c = 0;
	tmp = gc_malloc(1000);
	while (cmd->command[i + 1][k])
	{
		if (cmd->command[i + 1][k] == '"' || cmd->command[i + 1][k] == '\'')
		{
			(1) && (quote = cmd->command[i + 1][k++], tmp[c++] = quote);
			while (cmd->command[i + 1][k] != quote)
				tmp[c++] = cmd->command[i + 1][k++];
			tmp[c++] = cmd->command[i + 1][k++];
		}
		else if (cmd->command[i + 1][k] == '$' &&
				(cmd->command[i + 1][k + 1] == '"'
				|| cmd->command[i + 1][k + 1] == '\''))
			k++;
		else
			tmp[c++] = cmd->command[i + 1][k++];
	}
	ft_handle_quotes_norm(cmd, i, tmp, c);
}

static void	norm(char *input, int fd)
{
	ft_putstr_fd(input, fd);
	ft_putstr_fd("\n", fd);
	free(input);
}

void
	ft_process_input(t_command *cmd, int i, int fd, t_env *env)
{
	char	*input;

	exit_status(0, 1);
	while (1)
	{
		input = readline("> ");
		if (!input)
			break ;
		if (ft_strlen(input) == 0)
		{
			free(input);
			if (ft_strlen(remove_quotes(cmd->command[i + 1])) != 0)
				continue ;
			break ;
		}
		if (ft_strcmp(input, remove_quotes(cmd->command[i + 1])) == 0)
		{
			free(input);
			break ;
		}
		if (!ft_strchr(cmd->command[i + 1], '"')
			&& !ft_strchr(cmd->command[i + 1], '\''))
			ft_expansion_heredoc(&input, env);
		norm(input, fd);
	}
}
