/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:11:25 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 14:52:27 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_status(int new_stat, int set)
{
	static int	status;

	if (set)
		status = new_stat;
	return (status);
}

char	**ft_cpy_to_2d(t_env *tmp)
{
	char	**ret;
	int		len;
	int		i;
	int		total_len;

	(1) && (i = 0, len = ft_lstsize_env(tmp));
	ret = gc_malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	while (tmp)
	{
		if (tmp->variable_data == NULL)
			total_len = ft_strlen(tmp->variable_name) + 1;
		else
			total_len = ft_strlen(tmp->VN) + ft_strlen(tmp->VN) + 2;
		ret[i] = (char *)gc_malloc(total_len);
		if (!ret[i])
			return (NULL);
		if (tmp->variable_data == NULL)
			ret[i] = ft_strjoin(tmp->variable_name, "=");
		else
			ret[i] = ft_strjoin(ft_strjoin(tmp->VN, "="), tmp->variable_data);
		(1) && (i++, tmp = tmp->next);
	}
	return (ret[i] = NULL, ret);
}

int	check_syntax_1(char *s)
{
	gc_add(s);
	if (!s)
	{
		ft_putstr_fd("exit\n", 1);
		exit(exit_status(0, 0));
	}
	if (check_syntax(s) || check_quotes(s))
	{
		ft_putstr_fd("syntax error\n", 2);
		exit_status(258, 1);
		return (1);
	}
	return (0);
}

int
	main(int ac, char *av[], char **envp)
{
	t_env		*env;
	t_data		*data;
	t_command	*cmd;
	char		*line;
	char		*check;

	(1) && (data = NULL, env = NULL);
	if (*envp)
		create_env(envp, &env);
	while (1)
	{
		(close_fds()) && (data = set_data(data, ac, av), data->env = env);
		line = readline("\033[1;33mPowershell\033[1;34m $ \033[1;0m");
		add_history(line);
		if (check_syntax_1(line))
			continue ;
		gc_add(line);
		check = send_command(line);
		if (!check || !*check)
			continue ;
		cmd = fill_command(check);
		if (for_norm2(cmd))
			continue ;
		for_norm(cmd, data, env);
	}
}
