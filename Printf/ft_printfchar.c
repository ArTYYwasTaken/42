/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:46:05 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/01 20:42:40 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	unsigned char	res;
	int				total;

	total = 0;
	res = (unsigned char)c;
	total = write(1, &res, 1);
	return (total);
}