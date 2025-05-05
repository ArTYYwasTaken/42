/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:45:53 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/05 15:52:40 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static size_t	num_length(unsigned int n, size_t base_len)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

static void	ft_putnbrbase_str(unsigned int n, size_t base_len, ...)
{
	va_list	args;
	char	*base;
	char	*str;
	size_t	*i;

	va_start(args, base_len);
	base = va_arg(args, char *);
	str = va_arg(args, char *);
	i = va_arg(args, size_t *);
	if (n >= base_len)
		ft_putnbrbase_str(n / base_len, base_len, base, str, i);
	str[(*i)++] = base[n % base_len];
	va_end(args);
}

char	*ft_itoa_base(unsigned int num, char *base)
{
	char	*result;
	size_t	i;
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = num_length(num, base_len);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	ft_putnbrbase_str(num, base, result, &i, base_len);
	result[i] = '\0';
	return (result);
}
