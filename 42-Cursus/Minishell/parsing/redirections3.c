/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:06:39 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 09:55:40 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	a(char *cmd, int *k, char *tmp, int *c)
{
	char	quote;

	if (cmd[*k] == '"' || cmd[*k] == '\'')
	{
		(1) && (quote = cmd[*k], tmp[*c] = cmd[*k]);
		(1) && ((*k)++, (*c)++);
		while (cmd[*k] != quote)
			(1) && (tmp[*c] = cmd[*k], (*k)++, (*c)++);
		(1) && (tmp[*c] = cmd[*k], (*k)++, (*c)++);
	}
	else if (cmd[*k] == '$' && (cmd[*k + 1] == '"' || cmd[*k + 1] == '\''))
		(*k)++;
	else
		(1) && (tmp[*c] = cmd[*k], (*k)++, (*c)++);
}

void	b(t_command *cmd, int i)
{
	char		**sp;
	char		*s;
	int			j;

	j = 0;
	sp = split_quotes(cmd->command[i]);
	while (sp[j])
		(1) && (sp[j] = ft_strdup(sp[j]), j++);
	(1) && (j = 0, s = "");
	while (sp[j])
		(1) && (s = ft_strjoin(s, sp[j]), j++);
	free(cmd->command[i]);
	cmd->command[i] = ft_strdup(s);
}

void	norm_herdoc(t_norm_herdoc *d, t_command *cmd, t_env *env, int *i)
{
	if (!ft_strchr(cmd->command[*i + 1], '"')
		&& !ft_strchr(cmd->command[*i + 1], '\''))
		ft_expansion_heredoc(&d->input, env);
	free(d->input);
}
