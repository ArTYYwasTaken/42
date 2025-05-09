/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:53:14 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/11 15:53:16 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int		idest;
	int		isrc;

	idest = 0;
	isrc = 0;
	while (dest[idest] != '\0')
	{
		idest++;
	}
	while (src[isrc] != '\0')
	{
		dest[idest + isrc] = src[isrc];
		isrc++;
	}
	dest[idest + isrc] = '\0';
	return (dest);
}
/* int main()
{
	char str1[] = "Arthur ";
	char str2[] = "Leywin";

	printf("%s\n", ft_strcat(str1, str2));
	printf("%s\n", strcat(str1, str2));
} */