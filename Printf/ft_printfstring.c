/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:36:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/05 15:53:54 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printstring(const char *str)
{
	int	count;

	if (!str)
	{
		count += (write(1, "(null)", 6));
		return (count);
	}
	count = 0;
	count += write(1, str, ft_strlen(str));
	return (count);
}
