/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:43:06 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:43:06 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_strlcat appends the given string src to the end of 
	dest. It will append at most size and nul-terminate the result.

	Note : space for the terminating \0 character must be included in size.

	RETURN VALUE:
	The total length of the string that it tried to create : the initial
	length of dest + the length of src, with the goal to facilitate
	truncaction detection.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
// TEST CODE
int main ()
{
	char str[] = "Sosuke ";
	char str2[] = "Aizen";
	int n = 11;
	
	printf("%d\n", ft_strlcat(str, str2, n));

	printf("%d\n", strlcat(str, str2, n));
	printf("%s\n", str);
} */