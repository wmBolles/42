/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:02:29 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:28:10 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_words(const char *s);
int	is_whitespace(char c);
int	is_quote(char c);

static int	word_len(const char *s)
{
	int		i;
	int		in_q;
	int		quote_char;

	i = 0;
	in_q = 0;
	while (s[i] && (in_q || (!is_whitespace(s[i]) && !in_q)))
	{
		if ((s[i] == '"') && !in_q)
		{
			in_q = 1;
			quote_char = s[i];
		}
		else if (s[i] == quote_char && in_q)
		{
			in_q = 0;
		}
		i++;
	}
	return (i);
}

static void	*ft_free(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (NULL);
}

static void	ft_fill_norm(t_fillnorm *d, char const *s, char **str)
{
	while (s[d->i] && (d->in_q || (!is_whitespace(s[d->i]) && !d->in_q)))
	{
		if (s[d->i] == d->quote_char && d->in_q)
			d->in_q = 0;
		else
			str[d->j][d->k++] = s[d->i];
		d->i++;
	}
	str[d->j++][d->k] = '\0';
}

static char	**ft_fill(char **str, const char *s)
{
	t_fillnorm	d;

	d.i = 0;
	d.j = 0;
	d.in_q = 0;
	while (s[d.i])
	{
		while (s[d.i] && is_whitespace(s[d.i]))
			d.i++;
		if (!s[d.i])
			break ;
		str[d.j] = gc_malloc(sizeof(char) * (word_len(s + d.i) + 1));
		if (!str[d.j])
			return (ft_free(str, d.j));
		d.k = 0;
		if (s[d.i] == '"')
		{
			d.quote_char = s[d.i++];
			d.in_q = 1;
		}
		ft_fill_norm(&d, s, str);
	}
	return (str[d.j] = NULL, str);
}

char	**split_with_quotes(const char *s)
{
	char	**str;

	if (!s)
		return (NULL);
	str = gc_malloc(sizeof(char *) * (count_words(s) + 1));
	if (!str)
		return (NULL);
	str = ft_fill(str, s);
	return (str);
}
