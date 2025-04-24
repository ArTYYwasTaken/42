/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:15:59 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 20:15:43 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_putchar_fd() function writes the character c to the file descriptor
	fd.

    PARAMETERS:
	- char c: The character to be written.
	- int fd: The file descriptor where the character will be written.

    RETURN VALUE:
	The ft_putchar_fd() function does not return a value.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
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