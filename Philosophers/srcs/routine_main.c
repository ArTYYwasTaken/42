/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/03/26 00:10:15 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_is_full(t_philo *philo)
{
	bool	full;

	pthread_mutex_lock(&philo->meal_mutex);
	full = philo->max_meals;
	pthread_mutex_unlock(&philo->meal_mutex);
	return (full);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		precise_sleep(data, data->time_to_eat / 2);
	while (!routine_should_stop(data))
	{
		if (philo_is_full(philo))
			break ;
		if (!take_forks_and_eat(philo))
			break ;
		print_status(philo, SLEEP);
		precise_sleep(data, data->time_to_sleep);
		print_status(philo, THINK);
		desync_philo(philo);
	}
	return (NULL);
}
