/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:12:10 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/20 23:28:24 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0x0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		str++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;

	ft_strlowcase(str);
	i = 0;
	check = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (check == 1)
			{
				str[i] -= 32;
				check = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			check = 0;
		else
			check = 1;
		i++;
	}
	return (str);
}
