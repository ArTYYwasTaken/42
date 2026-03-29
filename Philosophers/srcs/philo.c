/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:48:44 by kelle             #+#    #+#             */
/*   Updated: 2026/03/26 00:26:47 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("./philo philosophers die eat sleep (* philo eats)\n"));
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
