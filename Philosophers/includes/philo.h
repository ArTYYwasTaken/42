/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:39:52 by kelle             #+#    #+#             */
/*   Updated: 2026/03/26 00:26:47 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"

# define DEF_COLOR "\033[0;39m"
# define BLUE "\033[0;94m"
# define PINK "\033[38;2;247;168;184m"
# define WHITE "\033[0;97m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"

typedef struct s_philosopers
{
	int				id;
	int				meals_eaten;
	long			death_at;
	bool			eating;
	bool			max_meals;
	struct s_data	*data;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_data
{
	int				philo_amount;
	int				fork_amount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_amount;
	long			start_time;
	bool			meals_limiter;
	bool			philo_died;
	pthread_t		monitor_thread;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

typedef struct s_cleanup
{
	int				forks_to_destroy;
	int				meals_to_destroy;
	bool			has_print_mutex;
	bool			has_state_mutex;
}					t_cleanup;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

bool	philo_start(char **argv, t_data *data);
bool	thread_creation(t_data *data);
bool	init_global_mutexes(t_data *data, bool *has_print_mutex,
			bool *has_state_mutex);
bool	init_fork_mutexes(t_data *data, bool has_print_mutex,
			bool has_state_mutex);
bool	init_meal_mutexes(t_data *data, bool has_print_mutex,
			bool has_state_mutex);
void	set_forks(t_data *data, int i,
			pthread_mutex_t **left, pthread_mutex_t **right);
void	cleanup_data(t_data *data, t_cleanup cleanup);

void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
bool	routine_should_stop(t_data *data);
void	print_status(t_philo *philo, char *status);
void	precise_sleep(t_data *data, int time_in_ms);
void	desync_philo(t_philo *philo);
bool	take_forks_and_eat(t_philo *philo);

void	ft_putstr_fd(char *s, int fd);
void	print_error(char *msg);
long	get_timestamp(void);

#endif