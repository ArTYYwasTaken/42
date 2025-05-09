/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:30:37 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/07 10:43:14 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/* 
int main()
{   
    char vet[] = "Esse texto vai ser copiado.";
    char vet2[sizeof(vet)];
   
    printf("dest: %s \n",ft_strcpy(vet2, vet));
	printf("dest: %s \n",strcpy(vet2, vet));
    return(0);
}
 */
