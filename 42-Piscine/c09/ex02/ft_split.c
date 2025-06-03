/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:57:06 by wabolles          #+#    #+#             */
/*   Updated: 2023/08/03 21:41:10 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		sep_len(char *str, char *sep);
int		ft_wd_count(char *str, char *sep);
int		check_sep(char c, char *sep);
char	*ft_strdup(char *src, int size);

char	**ft_split(char *str, char *charset)
{
	char	**ptr;
	int		wd_count;
	int		i;
	int		j;

	wd_count = ft_wd_count(str, charset);
	ptr = (char **)malloc(sizeof(char *) * wd_count);
	if (ptr == 0)
		return (0);
	if (*str == 0)
	{
		ptr[0] = 0;
		return (ptr);
	}
	i = 0;
	j = 0;
	while (i < wd_count)
	{
		while (str[j] && check_sep(str[j], charset))
			j++;
		ptr[i++] = ft_strdup(str + j, sep_len(str + j, charset));
		j += sep_len(str + j, charset);
	}
	ptr[wd_count - 1] = 0;
	return (ptr);
}

int	check_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	ft_wd_count(char *str, char *sep)
{
	int		count;
	int		i;

	count = 0;
	i = 1;
	while (str[i])
	{
		while (str[i] && !check_sep(str[i], sep))
			i++;
		if ((check_sep(str[i], sep)
				|| str[i] == '\0') && !check_sep(str[i - 1], sep))
			count++;
		if (str[i] == '\0')
			break ;
		i++;
	}
	count++;
	return (count);
}

int	sep_len(char *str, char *sep)
{
	int		i;

	i = 0;
	while (str[i] && !check_sep(str[i], sep))
		i++;
	i++;
	return (i);
}

char	*ft_strdup(char *src, int size)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(size);
	if (ptr == 0)
		return (0);
	if (size)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
