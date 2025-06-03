/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrock_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:03:44 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 06:16:31 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_normm_fill(t_trok_norm *d, char *s, char **str)
{
	if (s[d->i] == '\'' || s[d->i] == '"')
	{
		d->quote = s[d->i++];
		str[d->j][d->k++] = d->quote;
		while (s[d->i] && s[d->i] != d->quote)
			str[d->j][d->k++] = s[d->i++];
		if (s[d->i])
			str[d->j][d->k++] = s[d->i++];
	}
	else
		str[d->j][d->k++] = s[d->i++];
}

void	norm_cw(char *quote, int *i, char *s)
{
	(*quote) = s[(*i)++];
	while (s[*i] && s[*i] != *quote)
		(*i)++;
	if (s[*i])
		(*i)++;
}

int
	word_len_trok(const char *s, char c)
{
	char		quote;
	int			i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (s[i])
				i++;
		}
		else
			i++;
	}
	return (i);
}
