/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:15:59 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/19 12:48:57 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void    ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* 
// TEST CODE
int main()
{
	int fd = open("kaio.txt", O_WRONLY | O_TRUNC);
	char str[] = "Kaio";
	for (size_t i = 0; i < ft_strlen(str); i++)
		ft_putchar_fd(str[i], fd);
	close(fd);
}
*/