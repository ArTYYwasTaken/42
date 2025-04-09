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

/*
	DESCRIPTION :
	This function ft_strlcpy copies up to size - 1 characters from the given
	string src to the given string dest, nul-terminating the result.

	Note : space for the terminating \0 character must be included in size.

	RETURN VALUE :
	The total length of the string that it tried to create : the length of
	src, with the goal to facilitate truncaction detection.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t srclen;
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
// TEST CODE
int main()
{
	char dest[10];
	char src[] = "Kaio";
	size_t n = 4;
	printf("%ld\n", ft_strlcpy(dest, src, n));
	printf("%ld\n", strlcpy(dest, src, n));
} */