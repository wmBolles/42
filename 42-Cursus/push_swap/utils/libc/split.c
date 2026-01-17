/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:01:40 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 22:24:53 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_spaces(char c)
{
	return (c == 32);
}

static void	*ft_leak(char **memory, int i)
{
	while (i >= 0)
	{
		free(memory[i]);
		i--;
	}
	free(memory);
	return (NULL);
}

static int	count_word(char *str)
{
	int		count;
	int		index;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (!is_spaces(str[index]))
		{
			count++;
			while (str[index] && !is_spaces(str[index]))
				index++;
		}
		else
			index++;
	}
	return (count);
}

static char	*wb_strdup(char *str)
{
	int		len;
	int		index;
	char	*s;

	len = 0;
	while (str[len] && !is_spaces(str[len]))
		len++;
	s = malloc(len + 1);
	if (!s)
		exit_err();
	index = 0;
	while (index < len)
	{
		s[index] = str[index];
		index++;
	}
	return (s[index] = '\0', s);
}

char	**ft_split(char *str)
{
	char	**words;
	int		index;
	int		size;

	size = count_word(str) + 1;
	words = malloc(sizeof(char *) * size);
	if (!words)
		exit_err();
	index = 0;
	while (*str)
	{
		if (!is_spaces(*str))
		{
			words[index] = wb_strdup(str);
			if (!words[index])
				return (ft_leak(words, index));
			index++;
			while (*str && !is_spaces(*str))
				str++;
		}
		else
			str++;
	}
	return (words[index] = NULL, words);
}
