/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:11:32 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/26 15:19:29 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <paths.h>
# include "gc.h"
# define VN variable_name

int	g_stat;

typedef struct s_command
{
	char				**command;
	int					fd_out;
	int					fd_in;
	int					fd_d_in;
	char				*heredoc_cmd;
	struct s_command	*next;
}	t_command;

typedef struct s_env
{
	char			*variable_name;
	char			*variable_data;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*env;
	char	*path;
	char	*shlvl;
	char	*pwd;
	int		no_pwd;
	char	*home;
	int		no_env;
	int		or_in;
	int		status;
	int		status2;
	pid_t	pid;
	int		pipe_ends[2];
	int		len;
	int		val;
}	t_data;

typedef struct fill
{
	int		i;
	int		j;
	int		k;
	int		in_q;
	int		quote_char;	
}	t_fillnorm;

typedef struct expand
{
	int		datalen;
	int		new_len;
	int		new_v_size;
	char	*new_v;
	char	*data;
	char	*var;
	int		i;
	int		j;
	int		k;
	int		m;
}	t_ex_herdoc;

typedef struct strtrok
{
	int		i;
	int		j;
	int		k;
	char	quote;
	int		word_len;
}	t_trok_norm;

typedef struct expansion
{
	int		count;
	char	**splitted;
	int		i;
	char	quote;
	int		k;
	int		kk;	
}	t_expansion_norm;

typedef struct s_expand_state
{
	int	i;
	int	new_len;
}	t_state;

typedef struct redirections
{
	char	*input;
	char	*tmp;
	int		k;
	int		c;
	int		fd;
}	t_norm_herdoc;

typedef struct red
{
	int		i;
	int		fd_write;
	int		fd_read;
	int		len;
	int		j;
}	t_red;

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_lstadd_back(t_command **lst, t_command *new);
t_command	*ft_lstnew(char **argument);
char		**ft_split_string(char const *s, const char *delimiters);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*split_pipe(char *s);
t_env		*create_env(char **envp, t_env **env);
t_env		*ft_lstnew_env(char *name, char *data);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
char		*ft_var_name(char *line);
void		ft_echo(char **arg, t_command *exec);
void		ft_execution(t_command *exec, t_data *data, t_env *env);
int			exit_status(int new_stat, int set);
void		ft_env(t_command *exec, t_data *data, t_env *env);
void		ft_error(char *str2, char *str3);
void		ft_exit(t_command *exec, char **arg);
void		ft_pwd(t_command *exec, t_env *env);
void		ft_cd(char *path, t_data *data, t_env *env);
char		*ft_lstfind_env(t_env **env, char *line, char *new_line);
char		**get_paths(char *path);
char		**get_args(t_command *exec);
char		**arg_join(char **args, char **arg);
char		*get_path(t_data *data, char *cmd, t_env *env);
int			ft_arglen(char **arg);
char		**split_with_quotes(const char *s);
void		ft_signal_c(int num);
char		**ft_cpy_to_2d(t_env *tmp);
void		ft_close_pipe(t_data *data);
int			is_empty(char *str);
char		*valid_cmd(char *cmd, char **paths, char *path);
char		*valid_path(char *cmd, char *line);
void		ft_execution_(t_command *exec, t_data *data, t_env *env);
void		ft_multi_childs(t_command *exec, t_data *data, t_env *env);
void		ft_void(t_data *data, t_command *exec, t_env *env);
void		ft_execute_pipe(t_command *exec, t_data *data, t_env *env);
int			check_builtin(t_command *exec, t_data *data, t_env *env);
void		ft_child(t_command *exec, t_env *env, char **new_env);
void		ft_fork(t_data *data, t_env *env, t_command *exec, char **new_env);
int			ft_lstsize_env(t_env *env);
char		*ft_get_line(t_env *env, char *line, int i);
int			ft_varsize(t_command *lst);
void		ft_export(t_command *exec, t_data *data, t_env *env, char **args);
char		*ft_remove_plus(char *line);
int			ft_valid_char(char c);
t_env		*ft_sort_env(t_env *env, int (*cmp)(const char *, const char *));
void		ft_print_export(t_command *exec, t_data *data, t_env *env);
t_env		*ft_lstcpy_env(t_env *env);
void		exportadd(t_env **env, char *name, char *var);
void		ft_unset(t_data **data, char **args, t_env *env);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_signal(void);
int			ft_lstsize(t_command *cmd);
char		*find_env_name(char **envp, int i);
char		*find_env_data(char **envp, int i);
char		*get_from_env(char *var, t_env **env);
t_env		*create_env(char **envp, t_env **env);
void		ft_expansion(t_command *cmd, t_env *env);
int			calculate_redirections(char *s);
int			check_quotes(char *s);
char		*send_command(char *s);
t_command	*fill_command(char *s);
int			check_syntax(char *s);
char		**ft_strtrok(char *s, char c);
void		ft_redirection(t_command *cmd, t_env *env);
void		ft_expansion_heredoc(char **s, t_env *env);
int			split_quotes_calcul(char *s);
char		**split_quotes(char *s);
char		*remove_quotes(char *s);
int			check_syntax_command(t_command *cmd);
void		for_norm(t_command *cmd, t_data *data, t_env *env);
int			for_norm2(t_command *cmd);
t_data		*set_data(t_data *data, int ac, char **av);
void		ft_normm_fill(t_trok_norm *d, char *s, char **str);
void		norm_cw(char *quote, int *i, char *s);
int			word_len_trok(const char *s, char c);
int			split_quotes_calcul(char *s);
void		split_quotes_calcul_norm(char *s, int *index, int *count);
int			split_quotes_norm(char *s, t_expansion_norm *d);
int			norm2(char **s, t_expansion_norm *d);
void		check_expand(char **s, t_env *env);
char		*ft_expand(char *s, t_env *env);
char		*expand_status(char *new_value, int *new_length, int *i);
int			skip_special_var(const char *s, int i);
char		*expand_variable(const char *s, char *nv, t_env **e, t_state *t);
void		handle_expansion(char **cmd, t_env *env);
char		*ps(char **splitted);
int			check_double_quote(char *s, int *i);
int			check_single_quote(char *s, int *i);
int			check_quotes(char *s);
int			calculate_redirections(char *s);
int			check1(char **command, int i);
int			check2(char **command, int i);
int			check_syntax(char *s);
void		ft_output(t_command *cmd, int i);
void		ft_input(t_command *cmd, int i);
void		ft_append(t_command *cmd, int i);
void		a(char *cmd, int *k, char *tmp, int *c);
void		b(t_command *cmd, int i);
void		norm_herdoc(t_norm_herdoc *d, t_command *cmd, t_env *env, int *i);
void		norm_red2(t_red *d, t_command *cmd, t_env *env);
void		ft_heredoc(t_command *cmd, int i, int fd, t_env *env);
int			close_fds(void);
void		ft_process_input(t_command *cmd, int i, int fd, t_env *env);
void		ft_handle_quotes(t_command *cmd, int i);
void		ft_handle_quotes_norm(t_command *cmd, int i, char *tmp, int c);

#endif