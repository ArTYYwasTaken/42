/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:32 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 20:41:26 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_putstr_fd() function writes the string s to the file descriptor fd.
	It does not write a null terminator at the end of the string.

    PARAMETERS:
	- char *s: The string to be written.
	- int fd: The file descriptor where the string will be written.

    RETURN VALUE:
	None. The function does not return a value.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
