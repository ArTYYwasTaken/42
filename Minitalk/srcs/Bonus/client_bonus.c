/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 06:39:25 by marvin            #+#    #+#             */
/*   Updated: 2025/10/13 16:23:03 by kemontei         ###   ########.fr       */
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
	while(i >= 0)
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

void	server_signal(int signal)
{
	ft_printf("Server Received bit: ");
	if (signal == SIGUSR1)
		ft_printf("1\n");
	else if (signal == SIGUSR2)
		ft_printf("0\n");
}

int main(int argc, char  *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Prototype: %s <server_pid> <message>\n", argv[0]);
		exit (0);
	}
	signal(SIGUSR1, server_signal);
	signal(SIGUSR2, server_signal);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while(message[i])
		send_signals(server_pid, message[i++]);
	send_signals(server_pid, '\0');
}
