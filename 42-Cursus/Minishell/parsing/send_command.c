/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:11:16 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:56 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_quotes(char *s, char *str, int *i, int *j)
{
	char	q;

	(1) && (q = s[*i], str[*j] = s[*i], (*i)++, (*j)++);
	while (s[*i] && s[*i] != q)
		(1) && (str[*j] = s[*i], (*i)++, (*j)++);
	(1) && (str[*j] = s[*i], (*i)++, (*j)++);
}

static void	handle_redirections(char *s, char *str, int *i, int *j)
{
	(1) && (str[*j] = ' ', (*j)++, str[*j] = s[*i]);
	(1) && ((*j)++, (*i)++);
	if (s[*i] == s[*i - 1])
		(1) && (str[*j] = s[*i], (*j)++, (*i)++);
	(1) && (str[*j] = ' ', (*j)++);
}

char	*send_command(char *s)
{
	char	*str;
	int		i;
	int		j;
	int		slen;

	slen = ft_strlen(s) + calculate_redirections(s);
	(1) && (i = 0, j = 0, str = gc_malloc(slen + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			handle_quotes(s, str, &i, &j);
		else if (s[i] != '|' && s[i] != '<' && s[i] != '>')
			str[j++] = s[i++];
		else if (s[i] == '|' || s[i] == '<' || s[i] == '>')
			handle_redirections(s, str, &i, &j);
	}
	return (str[j] = '\0', str);
}

t_command
	*fill_command(char *s)
{
	t_command		*cmd_lst;
	char			**pipe_cmd;
	char			**command;
	t_command		*new_node;
	int				i;

	(1) && (i = 0, pipe_cmd = ft_strtrok(s, '|'), cmd_lst = NULL);
	while (pipe_cmd[i])
	{
		command = ft_strtrok(pipe_cmd[i], ' ');
		new_node = ft_lstnew(command);
		ft_lstadd_back(&cmd_lst, new_node);
		i++;
	}
	return (cmd_lst);
}

int
	check_syntax_command(t_command *cmd)
{
	int		i;

	while (cmd)
	{
		i = 0;
		while (cmd->command[i])
		{
			if (check1(cmd->command, i))
				return (1);
			i++;
		}
		i = 0;
		while (cmd->command[i])
		{
			if (check2(cmd->command, i))
				return (1);
			i++;
		}
		cmd = cmd->next;
	}
	return (0);
}
