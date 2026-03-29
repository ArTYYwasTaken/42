/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:38:00 by kelle             #+#    #+#             */
/*   Updated: 2026/03/26 00:26:47 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_data(t_data *data, t_cleanup cleanup)
{
	int	meal_index;

	if (!data)
		return ;
	while (data->philos && cleanup.meals_to_destroy > 0)
	{
		meal_index = --cleanup.meals_to_destroy;
		pthread_mutex_destroy(&data->philos[meal_index].meal_mutex);
	}
	while (data->forks && cleanup.forks_to_destroy > 0)
		pthread_mutex_destroy(&data->forks[--cleanup.forks_to_destroy]);
	if (cleanup.has_state_mutex)
		pthread_mutex_destroy(&data->state_mutex);
	if (cleanup.has_print_mutex)
		pthread_mutex_destroy(&data->print_mutex);
	free(data->philos);
	free(data->forks);
	data->philos = NULL;
	data->forks = NULL;
}
