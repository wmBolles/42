/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:10:31 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/13 13:08:03 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	char			*c_src;
	char			*c_dst;

	c_src = (char *)src;
	c_dst = (char *)dst;
	if (!c_dst && !c_src)
		return (NULL);
	index = 0;
	while (index < n)
	{
		c_dst[index] = c_src[index];
		index++;
	}
	return (c_dst);
}
