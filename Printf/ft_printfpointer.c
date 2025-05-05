/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:35:13 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 13:25:10 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printfpointer(void *ptr)
{
	int		total;
	char	*str;

	total = 0;
	if (!ptr)
	{
		total += write(1, "(nil)", 5);
		return (total);
	}
	str = ft_ulitoa_base((unsigned long int)ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	total += write(1, str, ft_strlen(str));
	free(str);
	return (total);
}
