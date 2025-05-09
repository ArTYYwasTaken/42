/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:32 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:12:53 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
int main()
{
	int fd = open("kaio.txt", O_TRUNC | O_WRONLY);
	if (fd == -1)
		return (1);
	char str[] = "Hello, World!";
	ft_putstr_fd(str, fd);
	close(fd);
}
*/