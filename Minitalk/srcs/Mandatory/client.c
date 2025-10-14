/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 06:39:25 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 19:57:14 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	send_signals(int pid, unsigned char c)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = c >> i;
		if (bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Prototype: %s <server_pid> <message>\n", argv[0]);
		exit (0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signals(server_pid, message[i++]);
	send_signals(server_pid, '\0');
}
