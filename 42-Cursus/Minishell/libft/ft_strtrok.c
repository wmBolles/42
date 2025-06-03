/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:10:32 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:28:59 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char *s, char c)
{
	int		i;
	int		words;
	char	quote;

	(1) && (i = 0, words = 0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
			{
				if (s[i] == '\'' || s[i] == '\"')
					norm_cw(&quote, &i, s);
				else
					i++;
			}
		}
	}
	return (words);
}

static void	*ft_free(char **str, int i)
{
	while (i--)
		free(str[i]);
	free (str);
	return (NULL);
}

char	**ft_fill(char **str, char *s, char c)
{
	t_trok_norm	d;	

	d.i = 0;
	d.j = 0;
	while (s[d.i] != 0)
	{
		while (s[d.i] != 0 && s[d.i] == c)
			d.i++;
		if (s[d.i] != 0)
		{
			d.word_len = word_len_trok(&s[d.i], c);
			str[d.j] = gc_malloc(d.word_len + 1);
			if (str[d.j] == 0)
				return (ft_free(str, d.j));
			d.k = 0;
			while (s[d.i] != 0 && (s[d.i] != c))
				ft_normm_fill(&d, s, str);
			(1) && (str[d.j][d.k] = '\0', d.j++);
		}
	}
	return (str[d.j] = 0, str);
}

char	**ft_strtrok(char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = gc_malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	str = ft_fill(str, s, c);
	return (str);
}
