/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:14:02 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/11 22:25:01 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*allocation;
	size_t	index;

	if ((ssize_t)count < 0 && (ssize_t)size < 0)
		return (NULL);
	allocation = malloc(count * size);
	if (!allocation)
		return (NULL);
	index = 0;
	while (index < (count * size))
	{
		*(allocation + index) = '\0';
		index++;
	}
	return ((void *)allocation);
}
