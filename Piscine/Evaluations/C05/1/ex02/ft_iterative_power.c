/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:35:33 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/15 14:35:37 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	count;
	int	n;

	n = nb;
	count = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (count != power)
	{
		n *= nb;
		count++;
	}
	return (n);
}
/*
int main()
{
	printf("%d\n", ft_iterative_power(5,2));
}
*/