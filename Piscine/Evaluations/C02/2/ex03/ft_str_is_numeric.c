/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:00:11 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/10 21:02:09 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//1 NUMEROS E VAZIO
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	num[] = "123";
	char	letras[] = "ABC";
	char	mix[] = "1AB";
	char	vazio[5];
	int	a;
	int	b;
	int	c;
	int	d;
	a = ft_str_is_numeric(num);
	b = ft_str_is_numeric(letras);
	c = ft_str_is_numeric(mix);
	d = ft_str_is_numeric(vazio);
	printf("Só numeros: %i\n", a);
	printf("Só letras: %i\n", b);
	printf("Letras + Numeros: %i\n", c);
	printf("Vazio: %i\n", d);
	return (0);
}*/
