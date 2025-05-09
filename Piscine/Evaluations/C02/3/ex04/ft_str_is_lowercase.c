/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:39:35 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 04:26:44 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
    char *a1 = "jado";
    char *a2 = "Jado";

    printf("%s Funcionaou: %d\n", a1, ft_str_is_lowercase(a1));
    printf("%s Funcionaou: %d\n", a2, ft_str_is_lowercase(a2));
}*/
