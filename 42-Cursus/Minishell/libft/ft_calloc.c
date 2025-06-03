/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:14:02 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:27:33 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*allocation;
	size_t	index;

	if ((ssize_t)count < 0 && (ssize_t)size < 0)
		return (NULL);
	allocation = gc_malloc(count * size);
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
