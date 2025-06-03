/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:35:45 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/11/25 17:23:52 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_valid_unset(char *arg)
{
	if ((arg[0] >= 'a' && arg[0] <= 'z')
		|| (arg[0] >= 'A' && arg[0] <= 'Z') || arg[0] == '_')
		return (1);
	ft_error(ft_strjoin("unset: '", arg), "': not a valid identifier");
	exit_status(1, 1);
	return (0);
}

static int	ft_unset_arg(t_data **data, char *arg, t_env *p, t_env *tmp)
{
	while (p)
	{
		if (ft_strcmp(p->variable_name, arg) == 0)
		{
			if (tmp)
				tmp->next = p->next;
			else
				(*data)->env = p->next;
			p->variable_name = NULL;
			p->variable_data = NULL;
			p = NULL;
			return (0);
		}
		tmp = p;
		p = p->next;
	}
	return (1);
}

void	ft_unset(t_data **data, char **args, t_env *env)
{
	t_env	*p;
	t_env	*tmp;
	char	*pwd;
	int		i;

	i = 0;
	exit_status(0, 1);
	if (!data || !(*data) || !env || !args || !*args)
		return ;
	while (args && args[++i])
	{
		ft_valid_unset(args[i]);
		p = env;
		pwd = ft_lstfind_env(&env, "PWD", NULL);
		tmp = NULL;
		if (ft_strcmp(args[i], "PATH") == 0)
			ft_lstfind_env(&env, "PATH=", "");
		if (!ft_strcmp(args[i], "PWD") && pwd)
			(*data)->pwd = ft_strdup(pwd);
		if (!ft_unset_arg(data, args[i], p, tmp))
			return ;
	}
}
