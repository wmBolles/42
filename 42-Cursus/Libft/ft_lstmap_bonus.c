/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:47:21 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/07 03:20:57 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_free(t_list *node, void (*del)(void *))
{
	t_list	*next;

	while (node)
	{
		next = node->next;
		del(node->content);
		free(node);
		node = next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*root;
	t_list		*tmp;

	if (!f || !del)
		return (NULL);
	tmp = lst;
	root = NULL;
	while (lst)
	{
		new = ft_lstnew(NULL);
		if (!new)
		{
			ft_lstmap_free(root, del);
			return (NULL);
		}
		new->content = (*f)(lst->content);
		ft_lstadd_back(&root, new);
		lst = lst->next;
	}
	return (root);
}
