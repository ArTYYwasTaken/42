/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/04/07 03:15:16 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	wait_single_philo(t_philo *philo)
{
	while (!sim_should_stop(philo->data))
		usleep(500);
	pthread_mutex_unlock(philo->left_fork);
	return (false);
}

static void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->is_eating = true;
	philo->death_deadline_ms = get_timestamp() + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, EAT);
	sleep_ms_interruptible(philo->data, philo->data->time_to_eat);
}

static void	finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	if (philo->data->has_meal_limit
		&& philo->meals_eaten >= philo->data->meals_required)
		philo->reached_meal_limit = true;
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->meal_mutex);
}

bool	take_forks_and_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, FORK);
	if (philo->data->philo_amount == 1)
		return (wait_single_philo(philo));
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	start_eating(philo);
	finish_eating(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (true);
}
