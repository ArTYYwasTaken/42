/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:34:37 by tide-pau          #+#    #+#             */
/*   Updated: 2025/03/08 15:06:14 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0)
		return (0);
	i = nb;
	result = 1;
	while (i > 0)
	{
		result *= i;
		i--;
	}
	return (result);
}

int	main()
{
	int	nb;

	nb = 6;
	printf("Iteracao Factorial:---> %d\n", ft_iterative_factorial(nb));
	return (0);
}