/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:32:09 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/13 21:48:55 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
// CONVERTER PARA MAIUSCULAS

char	ft_strupcase(char	*str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (*str);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (*str);
}
/*
int     main (void)
{
	char 	a[] = "@rthur";
	char 	b[0];

	ft_strupcase(a);
	ft_strupcase(b);
	printf("String convertida: %s\n", a);
	printf("String convertida: %s\n", b);
	return (0);
}*/
