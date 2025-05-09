/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:17:49 by tide-pau          #+#    #+#             */
/*   Updated: 2025/03/10 13:56:54 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i != nb)
	{
		if (i == nb)
			return (0);
		i++;
	}
	return (i);
}
/*
int	main()
{
	printf("RaizQuadrada: --> %d\n", ft_sqrt(25));
	printf("RaizQuadrada: --> %d\n", ft_sqrt(36));
	printf("RaizQuadrada: --> %d\n", ft_sqrt(64));
	printf("RaizQuadrada: --> %d\n", ft_sqrt(7));
	return (0);
}
*/
