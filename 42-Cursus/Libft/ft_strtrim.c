/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:32:46 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/13 11:03:16 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_exist(char c, char *buff)
{
	int		index;

	index = 0;
	while (buff[index])
	{
		if (c == buff[index])
			return (1);
		index++;
	}
	return (0);
}

static int	get_the_end(char *str, int str_len, char *set)
{
	int		index;

	index = str_len - 1;
	while (index >= 0)
	{
		if (!is_exist(str[index], set))
			return (index);
		index--;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char		*cset;
	char		*res;
	int			index;

	str = (char *)s1;
	cset = (char *)set;
	if (!set || !s1)
		return (NULL);
	while (*str && is_exist(*str, cset))
		str++;
	res = malloc((get_the_end(str, ft_strlen(str), cset)) + 2);
	if (!res)
		return (NULL);
	index = 0;
	while (index <= get_the_end(str, ft_strlen(str), cset))
	{
		res[index] = str[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
