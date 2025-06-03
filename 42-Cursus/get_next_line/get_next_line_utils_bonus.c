/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:50:58 by wabolles          #+#    #+#             */
/*   Updated: 2023/12/16 10:51:56 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*wb_strjoin(char *s1, char *s2)
{
	int			index;
	int			index2;
	char		*join;

	if (!s1)
	{
		s1 = malloc(0x1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), s1 = NULL);
	join = malloc(wb_strlen(s1) + wb_strlen(s2) + 1);
	if (!join)
		return (free(s1), s1 = NULL);
	index = -1;
	while (s1[++index])
		join[index] = s1[index];
	index2 = -1;
	while (s2[++index2])
		join[index++] = s2[index2];
	join[index] = '\0';
	free(s1);
	return (join);
}

int	wb_strlen(char *str)
{
	int		index;

	if (!str)
		return (0);
	index = ~(-1);
	while (*(str + index))
		index += (2 >> 1);
	return (index);
}

int	check_newline(char *str)
{
	int		index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
