/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:18:46 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:28:33 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*allocation;
	int		index;

	allocation = (char *)gc_malloc(ft_strlen(s1) + 1);
	if (!allocation)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		allocation[index] = s1[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}
