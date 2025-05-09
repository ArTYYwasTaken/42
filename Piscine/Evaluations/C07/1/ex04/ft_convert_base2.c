/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:31:36 by migusant          #+#    #+#             */
/*   Updated: 2025/03/18 11:12:56 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_get_size_of_final_number(long number, int base);
int		ft_is_char_in_string(char ch, char *str);
int		ft_convert_str_to_long_int(char *str, char *base_from, int base);
int		ft_base_len(char *str);
int		ft_is_base_valid(char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_convert_to_base(long number, char *base_to, int base);

int	ft_is_char_in_string(char ch, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_str_to_long_int(char *str, char *base_from, int base)
{
	int		signal;
	long	long_int;

	signal = 1;
	long_int = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			signal = -signal;
		str++;
	}
	long_int = 0;
	if (ft_is_char_in_string(*str, base_from) == -1)
		return (-1);
	while (ft_is_char_in_string(*str, base_from) != -1)
	{
		long_int = long_int * base + ft_is_char_in_string(*str, base_from);
		str++;
	}
	return (long_int * signal);
}

int	ft_get_size_of_final_number(long number, int base)
{
	int	size;
	int	neg;

	if (number == 0)
		return (1);
	neg = 0;
	if (number < 0)
	{
		number = number * -1;
		neg = 1;
	}
	size = 0;
	while (number > 0)
	{
		number = number / base;
		size ++;
	}
	if (neg == 1)
		return (size + 1);
	return (size);
}

char	*ft_convert_to_base(long number, char *base_to, int base)
{
	char	*result;
	int		size;
	int		minus;

	size = ft_get_size_of_final_number(number, base);
	result = (char *)(malloc((size + 1) * sizeof(char)));
	*(result + size) = '\0';
	if (number == 0)
		*(result) = base_to[0];
	minus = 1;
	if (number < 0)
		minus = -1;
	number *= minus;
	while (number > 0)
	{
		size--;
		*(result + size) = base_to[number % base];
		number /= base;
	}
	if (minus == -1)
		*(result) = '-';
	return (result);
}
