/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:38:22 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 04:34:06 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}
/*int main(void)
{
    char *a1 = "Jado";
    char *a2 = "Jado\n";

    printf("%s Funcionando: %d\n", a1, ft_str_is_printable(a1));
    printf("%s Funcionando: %d\n", a2, ft_str_is_printable(a2));
}*/
