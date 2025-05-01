/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:35:15 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/01 20:42:31 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int check_conversions(va_list args, char c)
{
	int 	total;

	total = 0;
	if (c == 'c')
		total += ft_printfchar(va_arg(args, char));
	else if (c == 's')
		total += ft_printfstring(va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		total += ft_pritfdecimal(va_arg(args, int));
	
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] != '%')
			write(1, &str[i++], 1);
		total = check_conversions(args, str[i + 1]);
		i++;
	}
	va_end(args);
	return (total);
}