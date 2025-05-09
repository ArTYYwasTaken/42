/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:55:40 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 04:15:01 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
    char *i2 = "jado";
    char *i1 = "J do";
    

    printf("%s Funciona: %d\n", i2, ft_str_is_alpha(i2));
    printf("%s Funciona: %d\n", i1, ft_str_is_alpha(i1));
}*/
