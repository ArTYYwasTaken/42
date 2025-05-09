/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:01:15 by tide-pau          #+#    #+#             */
/*   Updated: 2025/03/10 12:30:04 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, --power));
}
/*
int	main()
{
	printf("Result: --> %d\n", ft_recursive_power(5, 3));
	printf("Result: --> %d\n", ft_recursive_power(5, 0));
	printf("Result: --> %d\n", ft_recursive_power(3, 3));
	return (0);
}
*/
