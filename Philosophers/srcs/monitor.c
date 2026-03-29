/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/03/26 00:05:19 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_has_died(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->state_mutex);
	stop = data->philo_died;
	pthread_mutex_unlock(&data->state_mutex);
	return (stop);
}

static void	set_dead_state(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->philo_died = true;
	pthread_mutex_unlock(&data->state_mutex);
}

static bool	all_philos_full(t_data *data)
{
	int		i;
	bool	all_full;

	if (!data->meals_limiter)
		return (false);
	i = 0;
	all_full = true;
	while (i < data->philo_amount)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (!data->philos[i].max_meals)
			all_full = false;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		if (!all_full)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_philo_death(t_data *data, int i)
{
	long	now;

	pthread_mutex_lock(&data->philos[i].meal_mutex);
	now = get_timestamp();
	if (!data->philos[i].eating && now >= data->philos[i].death_at)
	{
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		set_dead_state(data);
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %d %s%s%s", now - data->start_time,
			data->philos[i].id, RED, DIED, DEF_COLOR);
		pthread_mutex_unlock(&data->print_mutex);
		return (true);
	}
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!philo_has_died(data))
	{
		if (all_philos_full(data))
			return (set_dead_state(data), NULL);
		i = 0;
		while (i < data->philo_amount && !philo_has_died(data))
		{
			if (check_philo_death(data, i))
				return (NULL);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}
