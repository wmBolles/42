/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:25:04 by wabolles          #+#    #+#             */
/*   Updated: 2023/11/20 13:19:44 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*prev;

	if (!del || !lst)
		return ;
	curr = *lst;
	while (curr)
	{
		prev = curr;
		del(curr->content);
		curr = curr->next;
		free(prev);
	}
	*lst = NULL;
}
