/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:36:22 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/14 13:41:57 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
// CONVERTER PARA MINUSCULA

char	ft_strlowcase(char	*str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (*str);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (*str);
}

int     main (void)
{
	char 	a[] = "@RTHUR";

	ft_strlowcase(a);
	printf("String convertida: %s\n", a);
	return (0);
}
