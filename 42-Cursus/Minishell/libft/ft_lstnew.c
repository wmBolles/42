/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:05:36 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:27:51 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_lstnew(char **command)
{
	t_command	*new;

	new = gc_malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->command = command;
	new->next = NULL;
	new->fd_in = 0;
	new->fd_out = 1;
	return (new);
}

t_env	*ft_lstnew_env(char *name, char *data)
{
	t_env	*new;

	new = gc_malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->variable_name = name;
	new->variable_data = data;
	new->next = NULL;
	return (new);
}
