/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:35:32 by tide-pau          #+#    #+#             */
/*   Updated: 2025/03/10 12:30:02 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;
	int	p;

	n = nb;
	p = power;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (p > 1)
	{
		n = n * nb;
		p--;
	}
	return (n);
}
/*
int	main()
{
	printf("Result: --> %d\n", ft_iterative_power(5, 2));
	printf("Result: --> %d\n", ft_iterative_power(0, 0));
	printf("Result: --> %d\n", ft_iterative_power(3, 3));
	return (0);
}
*/
