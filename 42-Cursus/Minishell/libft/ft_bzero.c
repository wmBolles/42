/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:27:19 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/18 22:35:49 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bzero(void *s, size_t n)
{
	char			*byte;
	size_t			index;

	byte = (char *)s;
	index = 0;
	while (index < n)
	{
		byte[index] = '\0';
		index++;
	}
}
