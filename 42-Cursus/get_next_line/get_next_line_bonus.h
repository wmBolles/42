/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:51:00 by wabolles          #+#    #+#             */
/*   Updated: 2023/12/16 13:37:12 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3301
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		wb_strlen(char *str);
int		check_newline(char *str);
char	*get_next_line(int fd);
char	*_get_line(char	*prompt);
char	*update_rest(char *prompt);
char	*wb_strjoin(char *s1, char *s2);
char	*_read_line(int fd, char *prompt);

#endif