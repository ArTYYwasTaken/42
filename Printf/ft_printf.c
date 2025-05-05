/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:35:15 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/05 13:28:57 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int	check_conversions(va_list args, char c)
{
	int 	total;

	total = 0;
	if (c == 'c')
		total += ft_printfchar(va_arg(args, char));
	else if (c == 's')
		total += ft_printfstring(va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		total += ft_printfdecimal(va_arg(args, int));
	else if (c == 'u')
		total += ft_printfunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		total += ft_printfhexadecimal(va_arg(args, unsigned int), c);
	else if (c == 'p')
	{
		total += write(1, "0x", 2);
		total += ft_printfpointer(va_arg(args, unsigned long long));
	}
	else if (c == '%')
		total += write(1, "%", 1);
	return (total);
}

static int	handle_regular_chars(const char *str, size_t *i)
{
    int	total;

	total = 0;
    while (str[*i] && str[*i] != '%')
    {
        write(1, &str[(*i)++], 1);
        total++;
    }
    return (total);
}

static int	handle_conversions(const char *str, va_list args, size_t *i)
{
    int total;

	total = 0;
    if (str[*i + 1])
    {
        total += check_conversions(args, str[*i + 1]);
        *i += 2;
    }
    else
        (*i)++;
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
        total += handle_regular_chars(str, &i);
        if (str[i] == '%')
            total += handle_conversions(str, args, &i);
    }
    va_end(args);
    return (total);
}
