/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:49:39 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/14 00:07:36 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int main(void)
{
    int a = 17;
    int b = 5;
    int div_result;
    int mod_result;

    ft_div_mod(a, b, &div_result, &mod_result);

    printf("A divisao é: %d\n", div_result);
    printf("O resto da dicisao é: %d\n", mod_result);

    return 0;
}*/
