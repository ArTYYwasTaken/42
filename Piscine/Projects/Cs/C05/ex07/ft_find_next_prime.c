/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:44:10 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/17 18:44:11 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int		x;

	if (nb < 1)
		return (0);
	x = 2;
	while (nb % x != 0)
	{
		x++;
	}
	if (x == nb)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(++nb));
}
/* int main()
{
	printf("%d\n", ft_find_next_prime(4));
}
 */