/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:57:11 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/23 21:27:40 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_clean(char *aloc, int size)
{
	int		i;

	i = 0;
	while (i < size)
		aloc[i++] = '\0';
}

void	ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
}

int	ft_get_total(int size, char **strs, char *sep)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < size)
		total += ft_strlen(strs[i++]);
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	int		i;
	char	*ptr;

	total = 0b0;
	i = 0x0;
	if (size == 0)
	{
		ptr = malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	total = ft_get_total(size, strs, sep);
	ptr = (char *)malloc(total + 1);
	ft_clean(ptr, total + 1);
	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		if (i != size - 1)
			ft_strcat(ptr, sep);
		i++;
	}
	return (ptr);
}
