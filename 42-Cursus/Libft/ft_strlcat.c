/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:11:13 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/20 18:07:16 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	wb_strlen(char const *str, size_t dstsize)
{
	size_t	index;

	if (!str && dstsize == 0)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;
	size_t	j;

	index = wb_strlen(dst, dstsize);
	dst_len = wb_strlen(dst, dstsize);
	src_len = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dst_len)
		return (src_len + dstsize);
	j = 0;
	while (src[j] && j < (dstsize - dst_len - 1))
	{
		dst[index] = src[j];
		index++;
		j++;
	}
	dst[index] = '\0';
	return (dst_len + src_len);
}
