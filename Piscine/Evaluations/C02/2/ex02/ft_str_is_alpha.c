/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:45:13 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/13 21:44:21 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			++i;
		}
		else
		{
			i = 0;
			return (0);
		}
	}
	return (1);
}

int	main()
{
	char	name[] = "Teste";
	char	vazio[5];
	char	num[] = "4rthur";
	int	x;
	int	y;
	int	z;
	x = ft_str_is_alpha(name);
	y = ft_str_is_alpha(vazio);
	z = ft_str_is_alpha(num);
	printf("valor de int: %i\n", x);
	printf("valor de int: %i\n", y);
	printf("valor de int: %i\n", z);
	return 0;
}

