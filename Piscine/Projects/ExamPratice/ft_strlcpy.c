/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:31:06 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/15 20:31:07 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	if (size > 0)
	{
		while (src[src_len] != '\0')
			src_len++;
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (src_len);
}

int main()
{
	char s1[20];
	char s2[] = "jin mu won";
	int n = 0;

	printf("%d\n", ft_strlcpy(s1, s2, n));
	printf("%d \n", strlcpy(s1, s2, n));
	printf("%s\n", s1);
}