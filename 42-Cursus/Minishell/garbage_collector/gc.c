/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:05:28 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:36:21 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_garbage	**gc_list(void)
{
	static t_garbage	*list;

	return (&list);
}

void
	gc_add(void *ptr)
{
	t_garbage	**list;
	t_garbage	*new_node;

	list = gc_list();
	if (!ptr)
		exit(0);
	new_node = malloc(sizeof(t_garbage));
	if (!new_node)
		exit(0);
	new_node->ptr = ptr;
	new_node->next = *list;
	*list = new_node;
}

void
	*gc_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	gc_add(ptr);
	return (ptr);
}

void
	gc_free_all(void)
{
	t_garbage	**list;
	t_garbage	*current;
	t_garbage	*next;

	list = gc_list();
	current = *list;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	*list = NULL;
}
