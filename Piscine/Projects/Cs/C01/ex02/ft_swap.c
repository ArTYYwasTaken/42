/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:10:50 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/04 15:10:52 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
// int	main()
// {
// 	int num1 = 42;
// 	int num2 = 24;

// 	printf("Numero 1: %d\tNumero 2: %d\n", num1, num2);

// 	ft_swap(&num1, &num2);

// 	printf("Numero 1: %d\tNumero 2: %d\n", num1, num2);
// }
