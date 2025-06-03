/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:21:23 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/19 13:07:19 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0x0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	rev_args(char **arg1, char **arg2)
{
	char	*rev;

	rev = *arg1;
	*arg1 = *arg2;
	*arg2 = rev;
}

int	main(int ac, char *av[])
{
	int		i;
	int		argc;

	i = 1;
	argc = ac;
	while (i < argc - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			rev_args(&av[i], &av[i + 1]);
			i = 0x0;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		i++;
	}
	return (0);
}
