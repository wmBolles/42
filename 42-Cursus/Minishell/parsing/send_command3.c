/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:13:43 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 14:20:58 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	check1(char **cm, int i)
{
	if ((!ft_strcmp(cm[i], ">") || !ft_strcmp(cm[i], "<")
			|| !ft_strcmp(cm[i], ">>") || !ft_strcmp(cm[i], "<<"))
		&& cm[i + 1] && (!ft_strcmp(cm[i + 1], ">")
			|| !ft_strcmp(cm[i + 1], "<")
			|| !ft_strcmp(cm[i + 1], "|") || !ft_strcmp(cm[i + 1], ">>")
			|| !ft_strcmp(cm[i + 1], "<<")))
		return (1);
	return (0);
}

int
	check2(char **cm, int i)
{
	if (!cm[i + 1] && (!ft_strcmp(cm[i], ">") || !ft_strcmp(cm[i], "<")
			|| !ft_strcmp(cm[i], "|") || !ft_strcmp(cm[i], ">>")
			|| !ft_strcmp(cm[i], "<<")))
		return (1);
	return (0);
}

int	check_syntax(char *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		i--;
	if (i < 0)
		return (0);
	if (s[i] == '|' || s[i] == '<' || s[i] == '>')
		return (1);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '|')
		return (1);
	return (0);
}

int	close_fds(void)
{
	int		fd;

	fd = 3;
	while (fd < OPEN_MAX)
		close(fd++);
	return (1);
}
