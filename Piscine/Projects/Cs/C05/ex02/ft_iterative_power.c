/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:40:46 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/16 21:40:46 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int		i;
	int		n;

	i = 1;
	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
	{
		return (1);
	}
	while (i < power)
	{
		nb *= n;
		i++;
	}
	return (nb);
}
int main()
{
	int n = 5;
	int p = 2;

	printf("%d\n", ft_iterative_power(n, p));
}
