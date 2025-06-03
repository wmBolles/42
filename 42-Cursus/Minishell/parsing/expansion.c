/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:11:07 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:08 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_quotes(char *s)
{
	t_expansion_norm	d;

	if (split_quotes_norm(s, &d) == -1)
		return (NULL);
	while (*s)
	{
		if (*s == '\"' || *s == '\'')
		{
			if (norm2(&s, &d) == -1)
				return (NULL);
		}
		else if (*s)
		{
			d.kk = 0;
			while (s[d.kk] && s[d.kk] != '\'' && s[d.kk] != '\"')
				d.kk++;
			(1) && (d.splitted[d.i] = gc_malloc((d.kk + 1)), d.kk = 0);
			while (*s && *s != '\'' && *s != '\"')
				d.splitted[d.i][d.kk++] = *s++;
			(1) && (d.splitted[d.i][d.kk] = '\0', d.i++);
		}
	}
	return (d.splitted[d.i] = NULL, d.splitted);
}

char
	*remove_quotes(char *s)
{
	int		i;
	int		j;
	int		len;
	char	quote;
	char	*new;

	(1) && (i = 0, j = 0, len = ft_strlen(s));
	if (len == 0)
		return (NULL);
	new = gc_malloc(len + 1);
	while (*s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			(1) && (quote = s[i], i++);
			while (s[i] && s[i] != quote)
				(1) && (new[j] = s[i], j++, i++);
			if (s[i])
				i++;
		}
		else
			(1) && (new[j] = s[i], j++, i++);
	}
	return (new[j] = '\0', new);
}

char	*ft_expand(char *s, t_env *env)
{
	t_state			state;
	char			*nv;

	(1) && (state.i = 0, state.new_len = 0);
	nv = gc_malloc(10000000);
	if (!nv)
		return (NULL);
	while (s[state.i])
	{
		if (s[state.i] == '$' && s[state.i + 1] == '?')
			expand_status(nv, &state.new_len, &state.i);
		else if (skip_special_var(s, state.i))
			state.i += 2;
		else if (s[state.i] == '$' && ft_isalpha(s[state.i + 1]))
			expand_variable(s, nv, &env, &state);
		else
			nv[state.new_len++] = s[state.i++];
	}
	return (nv[state.new_len] = '\0', nv);
}

void
	ft_expansion(t_command *cmd, t_env *env)
{
	int		i;

	while (cmd)
	{
		i = 0;
		while (cmd->command[i])
		{
			if (i > 0 && ft_strcmp(cmd->command[i - 1], "<<"))
				handle_expansion(&cmd->command[i], env);
			if (i == 0)
				handle_expansion(&cmd->command[i], env);
			i++;
		}
		cmd = cmd->next;
	}
}
