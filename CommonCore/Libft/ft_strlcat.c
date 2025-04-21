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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
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
int main() {
    char dest[20] = "Hello";
    const char *src = " World!";
    size_t size = sizeof(dest);

    printf("\nBefore strlcat: dest = \"%s\"\n", dest);

    size_t result = ft_strlcat(dest, src, size);

    printf("After strlcat: dest = \"%s\"\n", dest);
    printf("Total length attempted: %zu\n", result);

    // Test with a smaller buffer
    char small_dest[10] = "Hi";
    size_t small_size = sizeof(small_dest);

    printf("\nBefore strlcat with small buffer: dest = \"%s\"\n", small_dest);

    result = ft_strlcat(small_dest, src, small_size);

    printf("After strlcat with small buffer: dest = \"%s\"\n", small_dest);
    printf("Total length attempted: %zu\n", result);

    // Test with an empty source
    char empty_src_dest[20] = "Hello";
    const char *empty_src = "";

    printf("\nBefore strlcat with empty source: dest = \"%s\"\n", empty_src_dest);

    result = ft_strlcat(empty_src_dest, empty_src, size);

    printf("After strlcat with empty source: dest = \"%s\"\n", empty_src_dest);
    printf("Total length attempted: %zu\n\n", result);

    return 0;
}
 */