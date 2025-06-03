/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:27:48 by wabolles          #+#    #+#             */
/*   Updated: 2023/12/16 15:05:44 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*prompt;
	char		*buff;

	if (read(fd, prompt, 0) == -1 || BUFFER_SIZE <= 0)
		return (free(prompt), prompt = NULL);
	prompt = _read_line(fd, prompt);
	if (!prompt)
		return (NULL);
	buff = _get_line(prompt);
	prompt = update_rest(prompt);
	return (buff);
}

char	*_read_line(int fd, char *prompt)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(prompt), NULL);
	read_bytes = 1;
	while (read_bytes != 0 && !check_newline(prompt))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(prompt), free(buff), buff = NULL, prompt = NULL);
		buff[read_bytes] = '\0';
		prompt = wb_strjoin(prompt, buff);
	}
	free(buff);
	return (prompt);
}

char	*_get_line(char	*prompt)
{
	char	*buff;
	int		index;

	if (!*prompt)
		return (NULL);
	index = 0;
	while (prompt[index] && prompt[index] != '\n')
		index++;
	buff = malloc(index + 2);
	if (!buff)
		return (NULL);
	index = 0;
	while (prompt[index] && prompt[index] != '\n')
	{
		buff[index] = prompt[index];
		index++;
	}
	if (prompt[index] == '\n')
	{
		buff[index] = prompt[index];
		index++;
	}
	return (buff[index] = '\0', buff);
}

char	*update_rest(char *prompt)
{
	int		index;
	int		j;
	char	*rest;

	index = 0;
	while (prompt[index] && prompt[index] != '\n')
		index++;
	if (!prompt[index])
		return (free(prompt), prompt = NULL);
	rest = malloc(wb_strlen(prompt) - index + 1);
	if (!rest)
		return (free(prompt), prompt = NULL);
	index++;
	j = 0;
	while (prompt[index])
		rest[j++] = prompt[index++];
	rest[j] = '\0';
	return (free(prompt), rest);
}
