/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:50:57 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 10:00:51 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_put_line(t_command *exec, char *var, char *name)
{
	ft_putstr_fd(name, exec->fd_out);
	ft_putstr_fd("=", exec->fd_out);
	ft_putstr_fd("\"", exec->fd_out);
	ft_putstr_fd(var, exec->fd_out);
	ft_putstr_fd("\"", exec->fd_out);
}

void	ft_print_export(t_command *exec, t_data *data, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable_name, "_")
			|| (data->no_env && !ft_strcmp(tmp->variable_name, "PATH"))
			|| (data->no_pwd && !ft_strcmp(tmp->variable_name, "OLDPWD")))
		{
			tmp = tmp->next;
			continue ;
		}
		ft_putstr_fd("declare -x ", exec->fd_out);
		if (tmp->variable_data)
		{
			ft_put_line(exec, tmp->variable_data, tmp->variable_name);
		}
		else
		{
			ft_putstr_fd(tmp->variable_name, exec->fd_out);
		}
		ft_putstr_fd("\n", exec->fd_out);
		tmp = tmp->next;
	}
}

void	exportadd(t_env **env, char *name, char *var)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable_name, name))
		{
			if (!tmp->variable_data)
				tmp->variable_data = ft_strdup(var);
			else
				tmp->variable_data = ft_strjoin(tmp->variable_data, var);
		}
		tmp = tmp->next;
	}
}
