/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:25:38 by wabolles          #+#    #+#             */
/*   Updated: 2024/12/01 11:58:15 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

enum e_status
{
	SUCCESS = 0,
	FAILURE = 1,
	TRUE	= 1,
	FALSE	= 0
};

typedef struct s_table	t_table;

typedef struct s_philo
{
	t_table				*table;
	int					pid;
	int					left;
	int					right;
	int					nmeals;
	long long			last_meal;
	pthread_t			tid;
}	t_philo;

typedef struct s_table
{
	int				n_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				max_meals;
	long long		first;
	pthread_mutex_t	check;
	pthread_mutex_t	printing;
	pthread_mutex_t	forks[200];
	t_philo			philos[200];
}					t_table;

int				parse_args(int ac, char **av, t_table *data);
int				usage_display(void);
ssize_t			ft_atoi(char *s);
int				err(char *error);
int				set_mutex(t_table *table);
void			set_philos(t_table *table);
long long		get_time(void);
long long		diff(long long past, long long now);
void			exact_sleep(long long time);
void			output(t_table *table, char *msg, int pid);
int				simulation(t_table *table);
void			quit_simualtion(t_table *table);

#endif
