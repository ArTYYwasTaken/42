/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:27:12 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/11 16:27:14 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idest;
	unsigned int	isrc;

	idest = 0;
	isrc = 0;
	while (dest[idest] != '\0')
	{
		idest++;
	}
	while (isrc < nb && src[isrc] != '\0')
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
	int nb = 6;

	printf("%s\n", ft_strncat(str1, str2, nb));
} */