/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 04:05:00 by kelle             #+#    #+#             */
/*   Updated: 2026/04/07 03:15:16 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	parse_positive_int(const char *str, int *value)
{
	size_t	i;

	if (!str || !str[0] || !value)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	*value = ft_atoi(str);
	if (*value <= 0)
		return (false);
	return (true);
}

static bool	initialize_data(char **argv, t_data *data)
{
	if (!parse_positive_int(argv[1], &data->philo_amount)
		|| !parse_positive_int(argv[2], &data->time_to_die)
		|| !parse_positive_int(argv[3], &data->time_to_eat)
		|| !parse_positive_int(argv[4], &data->time_to_sleep))
		return (false);
	if (data->philo_amount > 200)
		return (print_error("Philo amount must be below 200"), false);
	data->meals_required = 0;
	data->has_meal_limit = false;
	if (argv[5])
	{
		if (!parse_positive_int(argv[5], &data->meals_required))
			return (false);
		data->has_meal_limit = true;
	}
	data->fork_amount = data->philo_amount;
	data->start_time = get_timestamp();
	data->stop_simulation = false;
	return (true);
}

static bool	initialize_allocations(t_data *data)
{
	bool	has_print_mutex;
	bool	has_state_mutex;

	data->philos = malloc(data->philo_amount * sizeof(t_philo));
	data->forks = malloc(data->fork_amount * sizeof(pthread_mutex_t));
	if (!data->philos || !data->forks)
		return (free(data->philos), free(data->forks), data->philos = NULL,
			data->forks = NULL, print_error("Failed to alloc memory"), false);
	has_print_mutex = false;
	has_state_mutex = false;
	if (!init_global_mutexes(data, &has_print_mutex, &has_state_mutex))
		return (false);
	if (!init_fork_mutexes(data, has_print_mutex, has_state_mutex))
		return (false);
	if (!init_meal_mutexes(data, has_print_mutex, has_state_mutex))
		return (false);
	return (true);
}

static void	initialize_philos(t_data *data)
{
	int				i;
	t_philo			*philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	i = 0;
	while (i < data->philo_amount)
	{
		philo = &data->philos[i];
		philo->id = i + 1;
		set_forks(data, i, &left, &right);
		philo->left_fork = left;
		philo->right_fork = right;
		philo->death_deadline_ms = data->start_time + data->time_to_die;
		philo->meals_eaten = 0;
		philo->is_eating = false;
		philo->reached_meal_limit = false;
		philo->data = data;
		i++;
	}
}

bool	philo_start(char **argv, t_data *data)
{
	if (!initialize_data(argv, data))
		return (print_error("Invalid arguments"), false);
	if (!initialize_allocations(data))
		return (print_error("Initializing allocations/mutex"), false);
	initialize_philos(data);
	return (true);
}
