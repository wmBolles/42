/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:10:58 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 18:34:04 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	norm_fore_expand2(t_ex_herdoc *d, char *s)
{
	d->j = d->i + 1;
	while (ft_isalnum(s[d->j]))
		d->j++;
	d->var = gc_malloc(d->j - d->i);
}

static void	norm_for_expand(t_ex_herdoc *d, char *s, t_env *env)
{
	norm_fore_expand2(d, s);
	if (!d->var)
		return ;
	d->k = 0;
	while (d->i + 1 < d->j)
		d->var[d->k++] = s[++d->i];
	d->var[d->k] = '\0';
	d->data = get_from_env(d->var, &env);
	free(d->var);
	if (d->data)
	{
		d->datalen = ft_strlen(d->data);
		d->m = 0;
		while (d->m < d->datalen)
		{
			if (d->new_len >= d->new_v_size)
			{
				d->new_v_size *= 2;
				d->new_v = realloc(d->new_v, d->new_v_size);
				if (!d->new_v)
					return ;
			}
			d->new_v[d->new_len++] = d->data[d->m++];
		}
	}
}

char	*ft_expand_heredoc(char *s, t_env *env, char *res)
{
	t_ex_herdoc	*d;

	d = gc_malloc(sizeof(t_ex_herdoc));
	if (!d)
		return (NULL);
	d->new_v_size = 1000;
	d->new_v = gc_malloc(d->new_v_size);
	if (!d->new_v)
		return (free(d), NULL);
	d->i = 0;
	d->new_len = 0;
	while (s[d->i])
	{
		if (s[d->i] == '$' && s[d->i + 1] == 0)
		{
			d->new_v[d->new_len++] = s[d->i++];
			continue ;
		}
		else if (s[d->i] == '$' && s[d->i + 1] != 0)
			norm_for_expand(d, s, env);
		else
			d->new_v[d->new_len++] = s[d->i];
		d->i++;
	}
	return (d->new_v[d->new_len] = '\0', res = d->new_v, free(d), res);
}

void	check_expand_heredoc(char **s, t_env *env)
{
	char	*str;

	str = ft_expand_heredoc(*s, env, NULL);
	free(*s);
	*s = ft_strdup(str);
}

void	ft_expansion_heredoc(char **s, t_env *env)
{
	char		**splitted;
	int			index;
	char		*str;

	splitted = split_quotes(*s);
	if (splitted == NULL)
		return ;
	index = 0;
	while (splitted[index])
	{
		check_expand_heredoc(&splitted[index], env);
		index++;
	}
	str = ft_strdup("");
	index = 0;
	while (splitted[index])
	{
		str = ft_strjoin(str, splitted[index]);
		index++;
	}
	free(*s);
	*s = str;
}
