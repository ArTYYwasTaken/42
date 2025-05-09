/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:35:54 by arvieira          #+#    #+#             */
/*   Updated: 2025/03/13 21:41:46 by arvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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
		
int	main()
{
	char	src[] = "Arthur";
	char	dest[20];
	
	printf("Palavra armazenada em destination: %s\n", ft_strcpy(dest, src));
	printf("Palavra armazenada em destination: %s\n", strcpy(dest, src));
	return (0);
}

