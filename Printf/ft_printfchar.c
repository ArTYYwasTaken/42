/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:46:05 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/05 15:43:07 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printchar(int c)
{
	unsigned char	res;
	int				count;

	res = (unsigned char)c;
	count = write(1, &res, 1);
	return (count);
}
