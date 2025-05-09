/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:24:04 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/15 14:24:07 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	count;
	int	tmp;

	tmp = nb;
	count = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	while (count < nb)
	{
		tmp *= count;
		count++;
	}
	return (tmp);
}

/*
int main()
{
	printf("%d", ft_iterative_factorial(6));
}
*/