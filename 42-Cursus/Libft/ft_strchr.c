/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:37:38 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/20 11:27:29 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int					index;
	char				*cast;

	cast = (char *)s;
	index = 0;
	while (cast[index])
	{
		if (cast[index] == (char)c)
			return ((char *)cast + index);
		index++;
	}
	if ((char)c == cast[index])
		return ((char *)cast + index);
	return (NULL);
}
