/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:50:39 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/13 20:09:55 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*cast;
	char	*allocation;

	if (!s || !f)
		return (NULL);
	allocation = malloc(ft_strlen(s) + 1);
	if (!allocation)
		return (NULL);
	index = 0;
	cast = (char *)s;
	while (cast[index])
	{
		allocation[index] = (*f)(index, cast[index]);
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}
