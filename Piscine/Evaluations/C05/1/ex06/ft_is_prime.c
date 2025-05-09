/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:16 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/15 18:01:19 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (nb % i != 0)
		i++;
	if (i == nb)
		return (1);
	return (0);
}
/*
int main()
{
	printf("%d\n", ft_is_prime(15));
	printf("%d\n", ft_is_prime(-3));
	printf("%d\n", ft_is_prime(5));
	printf("%d\n", ft_is_prime(16));
}
*/
