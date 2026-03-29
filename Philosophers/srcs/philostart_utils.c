/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philostart_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/03/26 00:26:47 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks(t_data *data, int i,
		pthread_mutex_t **left, pthread_mutex_t **right)
{
	if (i % 2 != 0)
	{
		*left = &data->forks[i];
		*right = &data->forks[(i + 1) % data->philo_amount];
	}
	else
	{
		*left = &data->forks[(i + 1) % data->philo_amount];
		*right = &data->forks[i];
	}
}
