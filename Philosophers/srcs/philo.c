/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:48:44 by kelle             #+#    #+#             */
/*   Updated: 2026/04/07 03:17:01 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("./philo philosophers time_to_die time_to_eat time_to_sleep ");
		return (printf("[meals_required]\n"));
	}
	if (!philo_start(argv, &data))
		return (print_error("Error initializing data"), EXIT_FAILURE);
	if (!thread_creation(&data))
	{
		cleanup_data(&data, (t_cleanup){data.fork_amount,
			data.philo_amount, true, true});
		return (print_error("Failed thread creation"), EXIT_FAILURE);
	}
	cleanup_data(&data, (t_cleanup){data.fork_amount,
		data.philo_amount, true, true});
	return (EXIT_SUCCESS);
}
