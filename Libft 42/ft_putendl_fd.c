/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:38:46 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 20:40:58 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_putendl_fd() function writes the string s to the file descriptor fd
	followed by a newline character.

    PARAMETERS:
	- char *s: The string to be written.
	- int fd: The file descriptor where the string will be written.

    RETURN VALUE:
	None. The function does not return a value.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
