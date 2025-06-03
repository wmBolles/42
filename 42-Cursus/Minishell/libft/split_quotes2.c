/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:13:05 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/22 04:21:53 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

void	count_norm(const char *s, int *i, int *in_quotes, int *quote_char)
{
	(1) && (*quote_char = s[*i++], *in_quotes = 1);
	while (s[*i] && (s[*i] != *quote_char || *in_quotes))
	{
		if (s[*i] == *quote_char)
			(*in_quotes) = 0;
		(*i)++;
	}
	if (s[*i] == *quote_char)
		(*i)++;
}

int	count_words(const char *s)
{
	int		i;
	int		in_quotes;
	int		quote_char;
	int		count;

	(1) && (i = 0, in_quotes = 0, count = 0);
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i] == '"')
			count_norm(s, &i, &in_quotes, &quote_char);
		else
		{
			while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				i++;
		}
		count++;
	}
	return (count);
}
