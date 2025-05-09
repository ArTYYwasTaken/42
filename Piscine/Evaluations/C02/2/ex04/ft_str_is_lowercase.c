/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:46:30 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/13 21:45:01 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
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
int	main (void)
{
        char    num[] = "123";
        char    letras[] = "abc";
        char    mix[] = "Abc";
        char    vazio[5];
        int     a;
        int     b;
        int     c;
        int     d;
        a = ft_str_is_lowercase(num);
        b = ft_str_is_lowercase(letras);
        c = ft_str_is_lowercase(mix);
        d = ft_str_is_lowercase(vazio);
        printf("Só numeros: %i\n", a);
        printf("Só letras minusculas: %i\n", b);
        printf("Letras M e m: %i\n", c);
        printf("Vazio: %i\n", d);
        return (0);
}*/
