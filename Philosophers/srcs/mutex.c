/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:40:00 by kelle             #+#    #+#             */
/*   Updated: 2026/03/26 00:26:47 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	cleanup_mutex_error(t_data *data, t_cleanup cleanup)
{
	cleanup_data(data, cleanup);
	print_error("Failed mutex creation");
	return (false);
}

bool	init_global_mutexes(t_data *data, bool *has_print_mutex,
		bool *has_state_mutex)
{
	t_cleanup	cleanup;

	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		cleanup = (t_cleanup){0, 0, *has_print_mutex, *has_state_mutex};
		return (cleanup_mutex_error(data, cleanup));
	}
	*has_print_mutex = true;
	if (pthread_mutex_init(&data->state_mutex, NULL) != 0)
	{
		cleanup = (t_cleanup){0, 0, *has_print_mutex, *has_state_mutex};
		return (cleanup_mutex_error(data, cleanup));
	}
	*has_state_mutex = true;
	return (true);
}

bool	init_fork_mutexes(t_data *data, bool has_print_mutex,
		bool has_state_mutex)
{
	int			i;
	t_cleanup	cleanup;

	i = 0;
	while (i < data->fork_amount)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			cleanup = (t_cleanup){i, 0, has_print_mutex, has_state_mutex};
			return (cleanup_mutex_error(data, cleanup));
		}
		i++;
	}
	return (true);
}

bool	init_meal_mutexes(t_data *data, bool has_print_mutex,
		bool has_state_mutex)
{
	int			i;
	t_cleanup	cleanup;

	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
		{
			cleanup = (t_cleanup){data->fork_amount, i,
				has_print_mutex, has_state_mutex};
			return (cleanup_mutex_error(data, cleanup));
		}
		i++;
	}
	return (true);
}
