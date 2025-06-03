/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:14:08 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/31 18:09:32 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		str_len;
	int		i;
	char	*aloc;

	str_len = ft_strlen(str) + 1;
	aloc = (char *)malloc(str_len);
	if (aloc == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		aloc[i] = str[i];
		i++;
	}
	aloc[i] = '\0';
	return (aloc);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ptr;

	ptr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ptr == 0)
		return (0);
	i = 0;
	while (ac--)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = ft_strdup(av[i]);
		i++;
	}
	ptr[i].str = 0;
	return (ptr);
}
