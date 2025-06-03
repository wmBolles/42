/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:17:27 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/18 22:40:00 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t					index;
	unsigned char			*cast;

	index = 0;
	cast = (unsigned char *)b;
	while (index < len)
	{
		cast[index] = (unsigned char)c;
		index++;
	}
	return (cast);
}
