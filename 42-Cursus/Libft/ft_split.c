/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:33:21 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/21 18:33:37 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] != c)
		{
			count++;
			while (str[index] && str[index] != c)
				index++;
		}
		else
			index++;
	}
	return (count);
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

static char	*wb_cstrdup(char *str, char c, int *p)
{
	char	*allocation;
	int		index;
	int		len;

	len = 0;
	(*p)++;
	while (str[len] != c && str[len])
		len++;
	allocation = malloc(len + 1);
	if (!allocation)
		return (NULL);
	index = 0;
	while (index < len)
	{
		allocation[index] = str[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	char		*str;
	int			index;

	str = (char *)s;
	if (!str)
		return (NULL);
	split = malloc((sizeof(char *) * (word_count(str, c) + 1)));
	if (!split)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			split[index - 1] = wb_cstrdup(str, c, &index);
			if (split[index - 1] == NULL)
				return (ft_leak(split, index - 1));
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (split[index] = NULL, split);
}
