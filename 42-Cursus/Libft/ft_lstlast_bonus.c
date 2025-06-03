/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:38:36 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/10 23:14:46 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;
	int		index;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	index = 0;
	curr = lst;
	while (curr)
	{
		curr = curr->next;
		if (curr->next == NULL)
			return (curr);
	}
	return (curr);
}
