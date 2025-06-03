/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:37:51 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 17:24:24 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_lstfind_env(t_env **env, char *line, char *new_line)
{
	t_env	*tmp;
	int		n;

	if (!env || !line)
		return (NULL);
	(1) && (tmp = *env, n = ft_strlen(line));
	while (tmp)
	{
		if (tmp && ft_strcmp(tmp->variable_name, line) == 0
			&& (tmp->variable_name[n] == '\0' || tmp->variable_name[n] == '='))
		{
			if (!new_line || !*new_line)
			{
				if (tmp->variable_data)
					return (ft_strdup(tmp->variable_data));
				else
					return (ft_strdup(""));
			}
			tmp->variable_data = ft_strdup(new_line);
			return (ft_strdup(tmp->variable_data));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_get_line(t_env *env, char *line, int i)
{
	t_env	*tmp;
	char	*res;
	int		n;

	if (!env)
		return (NULL);
	tmp = env;
	n = ft_strlen(line);
	while (tmp)
	{
		if (tmp && !ft_strcmp(tmp->variable_name, line)
			&& (tmp->variable_name[n] == '\0' || tmp->variable_name[n] == '='))
		{
			res = ft_strdup(tmp->variable_data + i);
			return (res);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_lstcpy_env(t_env *env)
{
	t_env	*copy;
	t_env	*tmp;

	copy = NULL;
	while (env)
	{
		if (env->variable_data == NULL)
			tmp = ft_lstnew_env(ft_strdup(env->variable_name), NULL);
		else
			tmp = ft_lstnew_env(ft_strdup(env->variable_name),
					ft_strdup(env->variable_data));
		if (!tmp)
			return (NULL);
		ft_lstadd_back_env(&copy, tmp);
		env = env -> next;
	}
	return (copy);
}
