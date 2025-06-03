/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:07:48 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:28:15 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_delimiter(const char *s, const char *delimiters)
{
	if ((*s == '>' && *(s + 1) == '>') || (*s == '<' && *(s + 1) == '<'))
		return (2);
	if ((*s == '>' && *(s + 1) != '>') || (*s == '<' && *(s + 1) != '<'))
		return (1);
	while (*delimiters)
	{
		if (*s == *delimiters)
			return (1);
		delimiters++;
	}
	return (0);
}

static int	count_elements(const char *s, const char *delimiters)
{
	int	i;
	int	count;
	int	delim_len;

	i = 0;
	count = 0;
	while (s[i])
	{
		delim_len = is_delimiter(s + i, delimiters);
		if (delim_len)
		{
			count++;
			i += delim_len;
		}
		else
		{
			while (s[i] && !is_delimiter(s + i, delimiters))
				i++;
			count++;
		}
	}
	return (count);
}

static int	element_len(const char *s, const char *delimiters)
{
	int	len;
	int	delim_len;

	len = 0;
	delim_len = is_delimiter(s, delimiters);
	if (delim_len)
		return (delim_len);
	while (s[len] && !is_delimiter(s + len, delimiters))
		len++;
	return (len);
}

void	*ft_free(char **arr, int count);

static char	**ft_fill(char **arr, const char *s, const char *delimiters)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = element_len(s + i, delimiters);
		arr[j] = gc_malloc(sizeof(char) * (len + 1));
		if (!arr[j])
			return (ft_free(arr, j));
		ft_strncpy(arr[j], s + i, len);
		arr[j][len] = '\0';
		j++;
		i += len;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split_string(const char *s, const char *delimiters)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = gc_malloc(sizeof(char *) * (count_elements(s, delimiters) + 1));
	if (!arr)
		return (NULL);
	arr = ft_fill(arr, s, delimiters);
	return (arr);
}
