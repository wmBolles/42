/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:51:30 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 22:00:54 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	return (s1[index] - s2[index]);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		index;

	index = 0;
	if (dstsize != 0)
	{
		while (src[index] && index < dstsize - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;

	if (!s1 || !s2)
		exit_err();
	size = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(size + 1);
	if (!join)
		exit_err();
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	join += ft_strlen(s1);
	ft_strlcpy(join, s2, ft_strlen(s2) + 1);
	return (join - ft_strlen(s1));
}

void	exit_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
