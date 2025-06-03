/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:03:34 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:19 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char
	*expand_status(char *nv, int *new_length, int *i)
{
	char	*status;
	int		p;

	p = 0;
	status = ft_itoa(exit_status(0, 0));
	*i += 2;
	while (status[p])
		nv[(*new_length)++] = status[p++];
	return (free(status), nv);
}

int
	skip_special_var(const char *s, int i)
{
	int		a;
	int		b;
	int		c;

	a = (s[i] == '$');
	b = ft_isdigit(s[i + 1]);
	c = (s[i + 1] == '*' || s[i + 1] == '@');
	return (a && (b || c));
}

char
	*expand_variable(const char *s, char *nv, t_env **e, t_state *t)
{
	int			j;
	int			m;
	char		*var;
	char		*data;

	j = t->i + 1;
	while (ft_isalpha(s[j]))
		j++;
	var = gc_malloc(j - t->i);
	if (!var)
		return (NULL);
	ft_strncpy(var, &s[t->i + 1], j - t->i - 1);
	var[j - t->i - 1] = '\0';
	data = get_from_env(var, e);
	free(var);
	if (data)
	{
		m = 0;
		while (data[m])
			nv[t->new_len++] = data[m++];
	}
	return (t->i = j, nv);
}

void	handle_expansion(char **cmd, t_env *env)
{
	char	**sp;
	char	*res;
	int		j;

	sp = split_quotes(*cmd);
	if (!sp)
		return ;
	j = 0;
	while (sp[j])
	{
		if (sp[j + 1] && !ft_strcmp(sp[j], "$")
			&& (sp[j + 1][0] == '"' || sp[j + 1][0] == '\''))
		{
			j++;
			continue ;
		}
		check_expand(&sp[j], env);
		(1) && (sp[j] = ft_strdup(sp[j]), j++);
	}
	(1) && (res = ps(sp), free(*cmd), *cmd = ft_strdup(res));
	(1) && (free(res), j = 0);
	while (sp[j])
		free(sp[j++]);
	free(sp);
}

char	*ps(char **splitted)
{
	int		j;
	char	*res;

	(1) && (j = 0, res = ft_strdup(""));
	if (!res)
		return (NULL);
	while (splitted[j])
	{
		if (splitted[j + 1] && !ft_strcmp(splitted[j], "$")
			&& (splitted[j + 1][0] == '"' || splitted[j + 1][0] == '\''))
		{
			j++;
			continue ;
		}
		if (splitted[j] && *splitted[j])
			res = ft_strjoin(res, remove_quotes(splitted[j]));
		j++;
	}
	return (res);
}
