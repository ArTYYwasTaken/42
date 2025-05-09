/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:04:15 by aimalasi          #+#    #+#             */
/*   Updated: 2025/03/16 16:00:03 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	while (i > 0)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}
/*int	main(void)
{
	printf("%d", ft_iterative_factorial(5));
}*/
