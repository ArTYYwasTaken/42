/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:38:46 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:13:05 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
/*
int main()
{
	int fd = open("kaio.txt", O_TRUNC | O_WRONLY);
	if (fd == -1)
		return (1);
	char str[] = "Kaio bué fofo";
	ft_putendl_fd(str, fd);
	close(fd);
}
*/
