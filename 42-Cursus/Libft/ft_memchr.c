/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:06:11 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/20 17:52:51 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					index;
	unsigned char			*cast;

	index = 0;
	cast = (unsigned char *)s;
	while (index < n)
	{
		if (cast[index] == (unsigned char)c)
			return (cast + index);
		index++;
	}
	return (NULL);
}
