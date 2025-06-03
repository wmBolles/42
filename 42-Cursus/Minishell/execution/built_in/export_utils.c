/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:23:18 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 09:58:54 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_var_name(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (i > 0 && line[i - 1] == '+')
		i--;
	return (ft_substr(line, 0, i));
}

char	*ft_remove_plus(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '+')
		{
			while (line[++i])
				line[i - 1] = line[i];
			break ;
		}
	}
	line[i - 1] = '\0';
	return (line);
}

int	ft_valid_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if ((c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}

t_env	*ft_sort_env(t_env *env, int (*cmp)(const char *, const char *))
{
	t_env	*tmp;
	t_env	*t;
	char	*m;

	tmp = env;
	while (tmp && tmp->next)
	{
		t = tmp->next;
		while (t)
		{
			if (cmp(tmp->variable_name, t->variable_name) > 0)
			{
				m = tmp->variable_name;
				tmp->variable_name = t->variable_name;
				t->variable_name = m;
				m = tmp->variable_data;
				tmp->variable_data = t->variable_data;
				t->variable_data = m;
			}
			t = t->next;
		}
		tmp = tmp->next;
	}
	return (env);
}
