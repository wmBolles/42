/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:03:18 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 13:29:48 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_command *exec, t_env *env)
{
	char	*tmp;

	(void)env;
	(void)exec;
	exit_status(0, 1);
	tmp = getcwd(NULL, 0);
	if (tmp)
	{
		ft_putstr_fd(tmp, exec->fd_out);
		ft_putstr_fd("\n", exec->fd_out);
	}
	else
	{
		ft_putstr_fd("minishell: pwd: "
			"error retrieving current directory: getcwd: "
			"cannot access parent directories: No such file or directory\n", 2);
		exit_status(1, 1);
	}
	gc_add(tmp);
}
