/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:50:08 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/14 00:21:22 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*int main(void)
{
    int a = 17;
    int b = 5;

    printf("Antes da função:\n");
    printf("a = %d, b = %d\n", a, b);

    ft_ultimate_div_mod(&a, &b);

    printf("Depois da função:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}*/
