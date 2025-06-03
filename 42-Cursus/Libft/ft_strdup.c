/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:18:46 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/04 19:46:00 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*allocation;
	int		index;

	allocation = (char *)malloc(ft_strlen(s1) + 1);
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
