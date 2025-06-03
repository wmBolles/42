/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:01:07 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/29 18:45:39 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(char *str2, char *str3)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	ft_putstr_fd("\n", 2);
}

char	**get_paths(char *path)
{
	char	**paths;

	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	return (paths);
}

char	**get_args(t_command *exec)
{
	char	**arg;
	char	**args;

	arg = ft_split(exec->command[0], ' ');
	if (!arg || !arg[0])
		return (NULL);
	args = arg_join(arg, &exec->command[1]);
	if (!args || !args[0])
		return (NULL);
	return (args);
}

char	**arg_join(char **args, char **arg)
{
	int		i;
	int		j;
	char	**new_args;

	i = 0;
	j = 0;
	if (!args && !*args)
		return (arg);
	if (!arg && !*arg)
		return (args);
	while (args && args[i])
		i++;
	while (arg && arg[j])
		j++;
	new_args = gc_malloc(sizeof(char *) * (i + j + 1));
	if (!new_args)
		return (NULL);
	i = -1;
	while (args && args[++i])
		new_args[i] = ft_strdup(args[i]);
	j = -1;
	while (arg && arg[++j])
		new_args[i++] = ft_strdup(arg[j]);
	new_args[i] = NULL;
	return (new_args);
}

char	*get_path(t_data *data, char *cmd, t_env *env)
{
	char	**paths;
	char	*tmp;
	char	*path;
	int		i;

	(void)data;
	paths = get_paths(ft_lstfind_env(&env, "PATH", NULL));
	i = -1;
	while (paths && paths[++i])
	{
		(1) && (tmp = ft_strjoin(paths[i], "/"), path = ft_strjoin(tmp, cmd));
		if (!access(path, F_OK | X_OK))
			return (path);
	}
	return (cmd);
}
