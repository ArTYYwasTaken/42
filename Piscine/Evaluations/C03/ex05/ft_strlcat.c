/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinto-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:58:57 by jpinto-r          #+#    #+#             */
/*   Updated: 2025/03/19 17:52:11 by jpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	teste(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = teste(dest);
	src_len = teste(src);
	i = 0;
	if (size > dest_len)
	{
		while (src[i] != '\0' && dest_len + i < size - 1)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}
/*
int main() {
    char dest[20] = "Hello, ";
    char src[] = "world! NANI";
    unsigned int size = sizeof(dest);
    unsigned int result = ft_strlcat(dest, src, size);

    printf("Result: %u\n", result);
    printf("Dest: %s\n", dest);

    return 0;
}*/