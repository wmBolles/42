/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:01:15 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 18:17:11 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtin(t_command *exec, t_data *data, t_env *env)
{
	if (exec->command && !ft_strcmp(exec->command[0], "echo"))
		return (ft_echo(exec->command + 1, exec), 1);
	if (exec->command && !ft_strcmp(exec->command[0], "pwd"))
		return (ft_pwd(exec, env), 1);
	if (exec->command &&!ft_strcmp(exec->command[0], "cd"))
		return (ft_cd(exec->command[1], data, env), data->no_pwd = 0, 1);
	if (exec->command && !ft_strcmp(exec->command[0], "unset"))
		return (ft_unset(&data, exec->command, env), 1);
	if (exec->command &&!ft_strcmp(exec->command[0], "env"))
	{
		if (exec->command[1])
			return (ft_putstr_fd("env: ", 1)
				, perror(exec->command[1]), exit_status(127, 1), 1);
		return (ft_env(exec, data, env), 1);
	}
	if (exec->command && !ft_strcmp(exec->command[0], "export"))
		return (ft_export(exec, data, env, exec->command), 1);
	return (0);
}

void	ft_child(t_command *exec, t_env	*env, char **new_env)
{
	char	*path;
	char	**args;

	args = get_args(exec);
	if (!args)
		(exit(exit_status(0, 1)));
	if (!args[0])
		(exit(exit_status(0, 1)));
	path = valid_path(args[0], ft_get_line(env, "PATH", 4));
	if (!path)
		return (ft_error(args[0], ": No such file or directory")
			, exit(exit_status(0, 0)));
	if (dup2(exec->fd_in, 0) == -1)
		(perror("dup2 error!\n"), exit(1));
	if (dup2(exec->fd_out, 1) == -1)
		(perror("dup2 error!\n"), exit(1));
	if (execve(path, args, new_env) == -1)
	{
		if (ft_strchr(args[0], '/'))
			(ft_error(args[0], \
				": is a directory"), exit(126));
		else
			(ft_error(args[0], \
				": command not found"), exit(127));
	}
}

void	ft_fork(t_data *data, t_env *env, t_command *exec, char **new_env)
{
	data->pid = fork();
	if (data->pid == -1)
		return (exit_status(1, 1), perror("fork"));
	if (data->pid == 0)
	{
		signal(SIGQUIT, ft_signal_c);
		ft_child(exec, env, new_env);
	}
	else
	{
		waitpid(data->pid, &data->status, 0);
		if (WIFSIGNALED(data->status))
		{
			exit_status(WTERMSIG(data->status) + 128, 1);
			if (WTERMSIG(data->status) == SIGQUIT)
				printf("Quit: 3\n");
			if (WTERMSIG(data->status) == SIGINT)
				ft_putstr_fd("\n", 1);
		}
		else
			exit_status(WEXITSTATUS(data->status), 1);
	}
}

void	ft_execution(t_command *exec, t_data *data, t_env *env)
{
	char	**new_env;

	if (!exec->command[0] || !exec->command
		|| (!exec->command[0] && !exec->command[1]))
		return ;
	if (is_empty(exec->command[0]))
	{
		ft_error(exec->command[0], ": command not found");
		exit_status(127, 1);
		return ;
	}
	if (!exec->command[0])
		return (exec->command++, ft_execution(exec, data, env));
	if (exec->command && !ft_strcmp(exec->command[0], "exit"))
		return (ft_exit(exec, exec->command));
	if (data)
		data->path = get_path(data, exec->command[ft_arglen(exec->command) - 1],
				env);
	if (check_builtin(exec, data, env))
		return ;
	new_env = ft_cpy_to_2d(env);
	ft_fork(data, env, exec, new_env);
}
