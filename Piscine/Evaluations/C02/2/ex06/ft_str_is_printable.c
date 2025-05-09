/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:38:34 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/13 21:47:28 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
// 1 caracter imprimivel OU VAZIA / 0 PARA OUTROS
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 31 && str[i] < 127)
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
        char    num[] = "\n";
        char    letras[] = "@rthur";
        char    mix[] = "%i\n";
        char    vazio[5];
        int     a;
        int     b;
        int     c;
        int     d;
        a = ft_str_is_printable(num);
        b = ft_str_is_printable(letras);
        d = ft_str_is_printable(vazio);
        printf("Quebra de linha dentro: %i\n", a);
        printf("Letras: %i\n", b);
        printf("Vazio: %i\n", d);
        return (0);
}*/
