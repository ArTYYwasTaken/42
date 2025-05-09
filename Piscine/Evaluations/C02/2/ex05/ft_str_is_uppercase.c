/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:10:23 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/10 21:12:32 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
// 1 MAIUSCULAS E VAZIO / 0 PARA OUTROS
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			++i;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int     main (void)
{
        char    num[] = "123";
        char    letras[] = "ABC";
        char    mix[] = "aBc";
        char    vazio[5];
        int     a;
        int     b;
        int     c;
        int     d;
        a = ft_str_is_uppercase(num);
        b = ft_str_is_uppercase(letras);
        c = ft_str_is_uppercase(mix);
        d = ft_str_is_uppercase(vazio);
        printf("Só numeros: %i\n", a);
        printf("Só letras MAIUSCULAS: %i\n", b);
        printf("Maiusculas e minusculas: %i\n", c);
        printf("Vazio: %i\n", d);
        return (0);
}*/
