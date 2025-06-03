/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:07:15 by wabolles          #+#    #+#             */
/*   Updated: 2023/07/15 17:02:42 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		i = 0x0;
		while (str[i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
				return (str);
			i++;
		}
		str++;
	}
	return (0);
}
