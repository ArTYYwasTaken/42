/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:59:22 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/04 16:59:25 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
// int main()
// {
// 	int a = 20;
// 	int b = 10;
// 	int *div;
// 	int *mod;
// 	ft_div_mod(a, b, &div, &mod);
// 	printf("Division : %d\tModulus: %d\n", div, mod);
// }