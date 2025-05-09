/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:40 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/15 16:21:43 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	temp;

	if (nb == 1)
		return (1);
	i = 0;
	while (i < nb)
	{
		temp = i * i;
		if (temp == nb)
			return (i);
		i++;
	}
	return (0);
}
/* 
int main()
{
	printf("%d\n", ft_sqrt(25));
	}
 */