/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:27 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:39:27 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The ft_memcmp function compares the first n bytes of the memory areas s1 and
	s2.
    It returns an integer less than, equal to, or greater than zero if the first
	n bytes of s1 is found, respectively, to be less than, to match, or be
	greater than the first n bytes of s2.

    PARAMETERS:
    - const void *s1: A pointer to the first memory area to be compared.
    - const void *s2: A pointer to the second memory area to be compared.
    - size_t n: The number of bytes to be compared.

    RETURN VALUE:
    Returns an integer less than, equal to, or greater than zero if the first n
	bytes of s1 is found, respectively, to be less than, to match, or be greater
	than the first n bytes of s2.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (i < n && ps1[i] == ps2[i])
		i++;
	if (i == n)
		return (0);
	return (ps1[i] - ps2[i]);
}
/* 
// TEST CODE
int main()
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    char str4[] = "Hello!";

    // Test 1: Identical strings
    printf("\n\n---//Test 1: Identical strings//---\n");
    printf("My ft_memcmp: %d\n", ft_memcmp(str1, str2, 5));
    printf("Original memcmp: %d\n", memcmp(str1, str2, 5));

    // Test 2: Different strings
    printf("\n---//Test 2: Different strings//---\n");
    printf("My ft_memcmp: %d\n", ft_memcmp(str1, str3, 5));
    printf("Original memcmp: %d\n", memcmp(str1, str3, 5));

    // Test 3: One string longer
    printf("\n---//Test 3: One string longer//---\n");
    printf("My ft_memcmp: %d\n", ft_memcmp(str1, str4, 5));
    printf("Original memcmp: %d\n", memcmp(str1, str4, 5));

    // Test 4: Empty comparison
    printf("\n---//Test 4: Empty comparison//---\n");
    printf("My ft_memcmp: %d\n", ft_memcmp(str1, str3, 0));
    printf("Original memcmp: %d\n", memcmp(str1, str3, 0));
	printf("\n\n");

    return 0;
}
 */