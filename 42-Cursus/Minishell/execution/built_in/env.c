/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:19:33 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 09:31:27 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_no_env(t_data *data, t_env *env)
{
	char	**paths;
	char	*tmp;
	char	*path;
	int		i;

	path = NULL;
	if (!ft_get_line(env, "PATH", 4)
		|| !ft_strlen(ft_get_line(env, "PATH", 4)))
		return (1);
	paths = get_paths(ft_lstfind_env(&env, "PATH", NULL));
	i = -1;
	while (paths && paths[++i])
	{
		(1) && (tmp = ft_strjoin(paths[i], "/"), path = ft_strjoin(tmp, "env"));
		data->path = ft_strdup(path);
		if (!access(path, F_OK | X_OK))
			return (0);
	}
	return (1);
}

void	ft_env(t_command *exec, t_data *data, t_env *env)
{
	exit_status(0, 1);
	if (check_no_env(data, env))
	{
		ft_error("env: ", "No such file or directory");
		return ((void)exit_status(127, 1));
	}
	data->env = env;
	ft_lstfind_env(&env, "_", data->path);
	while (env)
	{
		if (env->variable_data)
		{
			if ((data->no_env && !ft_strcmp(env->variable_name, "PATH="))
				|| (data->no_pwd && !ft_strcmp(env->variable_name, "OLDPWD=")))
			{
				env = env->next;
				continue ;
			}
			ft_putstr_fd(ft_strjoin(env->variable_name, "="), exec->fd_out);
			ft_putstr_fd(env->variable_data, exec->fd_out);
			ft_putstr_fd("\n", exec->fd_out);
		}
		env = env->next;
	}
}
