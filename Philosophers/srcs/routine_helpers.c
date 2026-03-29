/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/03/26 00:10:15 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	routine_should_stop(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->state_mutex);
	stop = data->philo_died;
	pthread_mutex_unlock(&data->state_mutex);
	return (stop);
}

static char	*get_status_color(char *status)
{
	if (ft_strncmp(status, FORK, ft_strlen(FORK) + 1) == 0)
		return (BLUE);
	if (ft_strncmp(status, EAT, ft_strlen(EAT) + 1) == 0)
		return (GREEN);
	if (ft_strncmp(status, SLEEP, ft_strlen(SLEEP) + 1) == 0)
		return (PINK);
	if (ft_strncmp(status, THINK, ft_strlen(THINK) + 1) == 0)
		return (WHITE);
	if (ft_strncmp(status, DIED, ft_strlen(DIED) + 1) == 0)
		return (RED);
	return (DEF_COLOR);
}

void	print_status(t_philo *philo, char *status)
{
	long	timestamp;
	char	*color;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!routine_should_stop(philo->data))
	{
		timestamp = get_timestamp() - philo->data->start_time;
		color = get_status_color(status);
		printf("%ld %d %s%s%s", timestamp, philo->id, color, status, DEF_COLOR);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	precise_sleep(t_data *data, int time_in_ms)
{
	long	start;

	start = get_timestamp();
	while (!routine_should_stop(data) && (get_timestamp() - start) < time_in_ms)
		usleep(500);
}

void	desync_philo(t_philo *philo)
{
	int	thinking_time;

	if (philo->data->philo_amount % 2 == 0)
		return ;
	thinking_time = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
	if (thinking_time <= 0)
		return ;
	if (thinking_time > philo->data->time_to_die / 2)
		thinking_time = philo->data->time_to_die / 2;
	precise_sleep(philo->data, thinking_time / 2);
}
