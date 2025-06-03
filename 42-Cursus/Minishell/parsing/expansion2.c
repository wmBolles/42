/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:23:16 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:16 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	split_quotes_calcul_norm(char *s, int *index, int *count)
{
	while (s[*index] && s[*index] != '\'' && s[*index] != '\"')
		(*index)++;
	(*count)++;
}

int
	split_quotes_calcul(char *s)
{
	int		i;
	int		count;
	char	quote;

	if (s == NULL)
		return (0);
	(1) && (i = 0, count = 0);
	while (s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			quote = s[i];
			i++;
			while (s[i] && s[i] != quote)
				i++;
			if (s[i])
				i++;
			count++;
		}
		else
			split_quotes_calcul_norm(s, &i, & count);
	}
	return (count);
}

int
	split_quotes_norm(char *s, t_expansion_norm *d)
{
	d->i = 0;
	d->count = split_quotes_calcul(s);
	if (d->count == 0)
		return (-1);
	d->splitted = gc_malloc(sizeof(char *) * (d->count + 1));
	if (!d->splitted)
		return (-1);
	return (0);
}

int
	norm2(char **s, t_expansion_norm *d)
{
	d->splitted[d->i] = gc_malloc(sizeof(char) * (strlen(*s) + 1));
	if (!d->splitted[d->i])
		return (-1);
	(1) && (d->quote = **s, d->k = 0);
	(1) && (d->splitted[d->i][d->k++] = d->quote, (*s)++);
	while (**s && **s != d->quote)
	{
		d->splitted[d->i][d->k++] = **s;
		(*s)++;
	}
	if (**s)
	{
		d->splitted[d->i][d->k++] = d->quote;
		(*s)++;
	}
	d->splitted[d->i][d->k] = '\0';
	return (d->i++, 0);
}

void
	check_expand(char **s, t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_expand(*s, env);
	if ((*s)[i] != '\'')
	{
		free (*s);
		*s = ft_strdup(str);
	}
}
