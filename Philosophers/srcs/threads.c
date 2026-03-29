/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:20:00 by kelle             #+#    #+#             */
/*   Updated: 2026/03/26 00:26:47 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_dead_state(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->philo_died = true;
	pthread_mutex_unlock(&data->state_mutex);
}

static void	join_created_threads(t_data *data, int created)
{
	int	joined;

	joined = 0;
	while (joined < created)
		pthread_join(data->philos[joined++].thread, NULL);
}

static bool	create_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]) != 0)
		{
			set_dead_state(data);
			join_created_threads(data, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	join_all_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (false);
		i++;
	}
	if (pthread_join(data->monitor_thread, NULL) != 0)
		return (false);
	return (true);
}

bool	thread_creation(t_data *data)
{
	if (!create_philo_threads(data))
		return (false);
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
	{
		set_dead_state(data);
		join_created_threads(data, data->philo_amount);
		return (false);
	}
	return (join_all_threads(data));
}
