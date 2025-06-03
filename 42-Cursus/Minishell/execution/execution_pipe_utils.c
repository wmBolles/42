/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipe_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:00:48 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/08/27 20:00:51 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	check_cmd(char *cmd)
{
	if (cmd[0] == '.' && cmd[1] == '\0')
	{
		ft_error(cmd, ": filename argument required");
		ft_putstr_fd(".: usage: . filename [arguments]\n", 2);
		exit(2);
	}
}

void	ft_close_pipe(t_data *data)
{
	close(data->pipe_ends[0]);
	close(data->pipe_ends[1]);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!str[0])
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*valid_cmd(char *cmd, char **paths, char *path)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!paths)
		return (exit_status(127, 1), NULL);
	if ((cmd[0] == '.' || cmd[0] == '/') && !access(cmd, F_OK))
		(ft_error(cmd, ": Permission denied"), exit(exit_status(126, 1)));
	if (cmd[0] == '.' || cmd[0] == '/')
		return (exit_status(127, 1), NULL);
	while (paths && paths[++i])
	{
		(1) && (tmp = ft_strjoin(paths[i], "/"), path = ft_strjoin(tmp, cmd));
		if (!access(path, F_OK | X_OK))
			return (path);
	}
	if (ft_strchr(cmd, '/'))
	{
		ft_error(cmd, ": No such file or directory");
		exit(exit_status(127, 1));
	}
	(ft_error(cmd, ": command not found"), exit(exit_status(127, 1)));
}

char	*valid_path(char *cmd, char *line)
{
	char	*path;

	path = NULL;
	if (!ft_strcmp(cmd, "minishell"))
		return (ft_error(cmd, ": command not found"), \
		exit(exit_status(127, 1)), NULL);
	if (cmd && ft_strlen(cmd))
	{
		if (!access(cmd, F_OK | X_OK))
			return (ft_strdup(cmd));
		return (check_cmd(cmd), valid_cmd(cmd, get_paths(line), path));
	}
	(ft_error(cmd, ": command not found"), exit(exit_status(127, 1)));
}
