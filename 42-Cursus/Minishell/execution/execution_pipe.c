/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:00:58 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 09:18:45 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execution_(t_command *exec, t_data *data, t_env *env)
{
	char	*path;
	char	**arr;
	char	**args;
	int		i;

	i = 0;
	if (!exec->command)
		exit(0);
	arr = ft_cpy_to_2d(env);
	if (exec->command && !ft_strcmp(exec->command[0], "exit"))
		return (ft_exit(exec, exec->command));
	if (check_builtin(exec, data, env))
		exit(exit_status(0, 0));
	args = get_args(exec);
	if (!args)
		return (exit(exit_status(0, 1)));
	if (!args[0])
		(exit(exit_status(0, 1)));
	path = valid_path(args[0], ft_get_line(env, "PATH", 5) + 5);
	if (!path)
		return (ft_error(args[0], ": No such file or directory")
			, exit(exit_status(0, 0)));
	if (execve(path, args, arr) == -1)
		(perror("execve"), exit(1));
}

void	ft_multi_childs(t_command *exec, t_data *data, t_env *env)
{
	if (dup2(exec->fd_in, 0) == -1)
		(exit(1));
	if (exec->next != NULL)
	{
		if ((exec->fd_out != 1) && dup2(exec->fd_out, 1) == -1)
			(exit(1));
		else if ((exec->fd_out == 1) && dup2(data->pipe_ends[1], 1) == -1)
			(exit(1));
	}
	else
	{
		if (dup2(exec->fd_out, 1) == -1)
			(exit(1));
	}
	ft_close_pipe(data);
	ft_execution_(exec, data, env);
}

void	ft_void(t_data *data, t_command *exec, t_env *env)
{
	while (exec)
	{
		if (pipe(data->pipe_ends) == -1)
			return (perror("pipe error!\n"));
		data->pid = fork();
		if (data->pid == -1)
			return (ft_error("fork: ", "Resource temporarily unavailable"),
				(void)exit_status(1, 1), exit(1));
		else if (data->pid == 0)
		{
			signal(SIGQUIT, ft_signal_c);
			ft_multi_childs(exec, data, env);
		}
		else
		{
			if (dup2(data->pipe_ends[0], 0) == -1)
				(perror("dup2 error!\n"), exit(1));
			ft_close_pipe(data);
		}
		exec = exec->next;
	}
	if (dup2(data->or_in, 0) == -1)
		(perror("dup2 error!\n"));
	(close(data->or_in), data->len = 0);
	return ;
}

void	ft_execute_pipe(t_command *exec, t_data *data, t_env *env)
{
	int	i;

	i = 0;
	data->status = 0;
	data->len = ft_varsize(exec);
	data->or_in = dup(STDIN_FILENO);
	if (data->or_in == -1)
		(perror("dup error!\n"), exit(1));
	ft_void(data, exec, env);
	waitpid(data->pid, &data->status, 0);
	while (waitpid(-1, &data->status2, 0) != -1)
		if (WTERMSIG(data->status2) == 2 || WTERMSIG(data->status) == 2)
			i = 1;
	if (i == 1)
		ft_putstr_fd("\n", 1);
	if (WIFSIGNALED(data->status))
	{
		exit_status(WTERMSIG(data->status) + 128, 1);
		if (WTERMSIG(data->status) == SIGQUIT)
			printf("Quit: 3\n");
	}
	else
		exit_status(WEXITSTATUS(data->status), 1);
}
