/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:28:03 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/24 20:28:03 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_substr() function allocates sufficient memory for a substring of
	the string s, starting from the index start and with a maximum length of
	len.

    PARAMETERS:
	- char const *s: The string from which the substring will be extracted.
	- unsigned int start: The starting index of the substring.
	- size_t len: The maximum length of the substring.

    RETURN VALUE:
	The ft_substr() function returns a pointer to the newly allocated substring,
	or NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (!len || start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s[start], len + 1);
	return (ptr);
}
/* 
int	main()
{
	// Test 1: Normal case
	char *s1 = ft_substr("Bankai", 1, 9);
	printf("\nTest 1: %s\n", s1);
	free(s1);

	// Test 2: start > strlen
	char *s2 = ft_substr("Bankai", 10, 5);
	printf("Test 2: %s\n", s2);
	free(s2);

	// Test 3: Length exceeds available characters
	char *s3 = ft_substr("Bankai", 3, 10);
	printf("Test 3: %s\n", s3);
	free(s3);

	// Test 4: Empty string
	char *s4 = ft_substr("", 0, 5);
	printf("Test 4: %s\n\n", s4);
	free(s4);

	return (0);
}
 */
