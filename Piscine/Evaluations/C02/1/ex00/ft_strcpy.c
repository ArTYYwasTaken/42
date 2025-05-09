/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigabrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:36:03 by tigabrie          #+#    #+#             */
/*   Updated: 2025/03/12 18:02:11 by tigabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)

{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	destino[10];
	char	origem[] = "bom dia";

	printf ("Origem: %s\nDestino: %s\n\n", origem, destino);
	ft_strcpy(destino, origem);
	printf ("Origem: %s\nDestino: %s\n\n", origem, destino);
	return(0);
}*/
