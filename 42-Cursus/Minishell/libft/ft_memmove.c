/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:07:58 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/18 22:39:56 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		index = 0;
		while (index < len)
		{
			*((char *)dst + index) = *((char *)src + index);
			index++;
		}
	}
	else
	{
		index = len;
		while (index > 0)
		{
			*((char *)dst + index - 1) = *((char *)src + index - 1);
			index--;
		}
	}
	return (dst);
}
