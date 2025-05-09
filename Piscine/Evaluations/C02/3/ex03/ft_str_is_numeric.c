/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:07:42 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 04:23:10 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
    char *a1 = "11111";
    char *a2 = "1111j";

    printf("%s Funciona: %d\n", a1, ft_str_is_numeric(a1));
    printf("%s Funciona: %d\n", a2, ft_str_is_numeric(a2));
}*/
