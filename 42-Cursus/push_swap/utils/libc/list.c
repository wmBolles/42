/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:09:32 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 10:58:40 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*curr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new;
}

t_node	*ft_lstnew(int content)
{
	t_node	*root;

	root = malloc(sizeof(t_node));
	if (!root)
		exit_err();
	root->digit = content;
	root->position = 0;
	root->index = -42;
	root->c = -42;
	root->next = NULL;
	return (root);
}

int	ft_lstsize(t_node *lst)
{
	int		count;
	t_node	*curr;

	if (!lst)
		return (0);
	count = 0;
	curr = lst;
	while (curr)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}

t_node	*last_node(t_node *lst)
{
	t_node	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr)
	{
		if (!curr->next)
			return (curr);
		curr = curr->next;
	}
	return (lst);
}
