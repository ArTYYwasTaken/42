/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:00:56 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 04:30:49 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *std)
{
	int	i;

	i = 0;
	while (std[i] != '\0')
	{
		if (!((std[i] >= 'A' && std[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
    char *a1 = "JADO";
    char *a2 = "Jado";

    printf("%s Funciona: %d\n", a1, ft_str_is_uppercase(a1));
    printf("%s Funciona: %d\n", a2, ft_str_is_uppercase(a2));
}*/
