/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:10:54 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/13 00:10:54 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env_name(char **envp, int i)
{
	int		j;
	char	*name;

	j = 0;
	while (envp[i][j] != '=')
		j++;
	name = gc_malloc(j + 1);
	if (!name)
		return (NULL);
	j = 0;
	while (envp[i][j] != '=')
	{
		name[j] = envp[i][j];
		j++;
	}
	name[j] = 0;
	i++;
	return (name);
}

char	*find_env_data(char **envp, int i)
{
	int		j;
	int		k;
	int		y;
	char	*data;

	(1) && (j = 0, k = 0, y = 0);
	while (envp[i][j] != '=')
		j++;
	j++;
	y = j;
	while (envp[i][j])
	{
		k++;
		j++;
	}
	data = gc_malloc(k + 1);
	if (!data)
		return (NULL);
	k = 0;
	while (envp[i][y])
		data[k++] = envp[i][y++];
	data[k] = 0;
	return (data);
}

char	*get_from_env(char *var, t_env **env)
{
	t_env	*head;

	head = *env;
	if (!env || !*env)
		return (NULL);
	while (head)
	{
		if (ft_strcmp(var, head->variable_name) == 0)
			break ;
		head = head->next;
	}
	if (head)
		return (head->variable_data);
	else
		return (NULL);
}

t_env	*create_env(char **envp, t_env **env)
{
	int		i;
	char	*name;
	char	*data;
	t_env	*env_node;

	i = 0;
	while (envp[i])
	{
		name = find_env_name(envp, i);
		data = find_env_data(envp, i);
		env_node = ft_lstnew_env(name, data);
		ft_lstadd_back_env(env, env_node);
		i++;
	}
	return (*env);
}
