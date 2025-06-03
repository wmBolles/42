/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:01 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/13 20:09:44 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		index;
	size_t		re;

	if (*to_find == '\0')
		return ((char *)(str));
	if (len == 0)
		return (NULL);
	index = 0;
	while (index < len && str[index])
	{
		re = 0;
		while (str[index + re] == to_find[re] && (index + re) < len)
		{
			if (to_find[re + 1] == '\0')
				return ((char *)(str + index));
			re++;
		}
		index++;
	}
	return (NULL);
}
