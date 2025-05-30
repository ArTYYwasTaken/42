/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:43:18 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:43:18 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
/* 
int main()
{
    const char *src = "Aoi Ashito";
    char dest[20];
    size_t result;

    result = ft_strlcpy(dest, src, sizeof(dest));

    printf("\nSource: %s\n", src);
    printf("Destination: %s\n", dest);
    printf("Length of source: %zu\n\n", result);

    return 0;
}
*/