/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:59:03 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 14:52:41 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_norm2(t_command *cmd)
{
	if (check_syntax_command(cmd))
	{
		ft_putstr_fd("syntax error\n", 2);
		exit_status(258, 1);
		return (1);
	}
	return (0);
}

void	for_norm(t_command *cmd, t_data *data, t_env *env)
{
	ft_expansion(cmd, env);
	ft_redirection(cmd, env);
	if (cmd->next)
		ft_execute_pipe(cmd, data, env);
	else
		ft_execution(cmd, data, env);
}

t_data	*set_data(t_data *data, int ac, char **av)
{
	(void)ac;
	(void)av;
	data = gc_malloc(sizeof(t_data));
	if (!data)
		exit(0);
	return (data);
}
