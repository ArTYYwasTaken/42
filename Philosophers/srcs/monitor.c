/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/04/07 03:15:16 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_stop_flag(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->stop_simulation = true;
	pthread_mutex_unlock(&data->state_mutex);
}

static bool	all_philos_full(t_data *data)
{
	int		i;
	bool	all_full;

	if (!data->has_meal_limit)
		return (false);
	i = 0;
	all_full = true;
	while (i < data->philo_amount)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (!data->philos[i].reached_meal_limit)
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
	if (!data->philos[i].is_eating
		&& now >= data->philos[i].death_deadline_ms)
	{
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		set_stop_flag(data);
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
	while (!sim_should_stop(data))
	{
		if (all_philos_full(data))
			return (set_stop_flag(data), NULL);
		i = 0;
		while (i < data->philo_amount && !sim_should_stop(data))
		{
			if (check_philo_death(data, i))
				return (NULL);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}
