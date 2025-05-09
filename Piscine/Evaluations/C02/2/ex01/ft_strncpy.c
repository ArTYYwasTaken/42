/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:35:21 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/06 10:25:14 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main()
{
	int 	lim;
	lim = 7;
	char src[] = "Arthur";//defini string 'src'com arthur
	char dest[15]; //deu um espaco em branco com 15 arrays
	printf("Conteúdo de dest: %s\n", ft_strncpy(dest, src, lim));
	printf("Conteúdo de dest: %s\n", strncpy(dest, src, lim));

	return (0);
}

