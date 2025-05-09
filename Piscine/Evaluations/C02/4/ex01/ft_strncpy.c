/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:39:51 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/07 10:46:05 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
int main(void)
{
    char    src[]= "Hello, world!";
    char    dest[]= "olaoiasodiaoidoasido";
    int n = 13;
    ft_strncpy(dest, src, n);
    printf("dest: %s\nn:%d\n", ft_strncpy(dest, src, n));
	printf("dest: %s\nn:%d\n", strncpy(dest, src, n));
}