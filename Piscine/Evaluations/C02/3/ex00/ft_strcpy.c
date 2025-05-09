/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbento-c <dbento-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:01:01 by dbento-c          #+#    #+#             */
/*   Updated: 2025/03/17 03:25:17 by dbento-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	dest[i] = src[i];
	return (dest);
}
int main(void)
{
    char    dest[] = "Desejado";
    char    src[] = "Jado";

    printf("Antes dest: %s\n", dest);
    ft_strcpy(dest, src);
    printf("Despios dest: %s\n", dest);
}
