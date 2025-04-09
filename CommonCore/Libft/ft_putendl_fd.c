/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:38:46 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:40:11 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(char *s)
{
	size_t i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putstr_fd(char *s, int fd)
{
	if(s)
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
}