/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:42:31 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 10:21:58 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	calculate_redirections(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == '|' || s[j] == '<' || s[j] == '>')
		{
			i++;
			if (s[j] == '>' && s[j + 1] == '>')
				j++;
			if (s[j] == '<' && s[j + 1] == '<')
				j++;
		}
		j++;
	}
	return (i * 2);
}

int
	check_double_quote(char *s, int *i)
{
	int	quote_found;

	quote_found = 0;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		(*i)++;
		quote_found = 1;
	}
	if (s[*i] != '\"')
		return (1);
	return (0);
}

int
	check_single_quote(char *s, int *i)
{
	int		quote_found;

	quote_found = 0;
	(*i)++;
	while (s[*i] && s[*i] != '\'')
	{
		(*i)++;
		quote_found = 1;
	}
	if (s[*i] != '\'')
		return (1);
	return (0);
}

int
	check_quotes(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|')
		{
			if (s[i + 1] == '|')
				return (1);
		}
		else if (s[i] == '\"')
		{
			if (check_double_quote(s, &i))
				return (1);
		}
		else if (s[i] == '\'')
		{
			if (check_single_quote(s, &i))
				return (1);
		}
		if (s[i])
			i++;
	}
	return (0);
}
