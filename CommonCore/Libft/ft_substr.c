/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/09 14:46:12 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:46:12 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s);
	if (!s || !len || start >= str_len)
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
// TEST CODE
int	main(void)
{
	// Test case 1: Normal case
	const char str1[] = "Bankai";
	unsigned int start1 = 1;
	size_t len1 = 9;
	char *result1 = ft_substr(str1, start1, len1);
	printf("Test 1: %s\n", result1);
	free(result1);

	// Test case 2: Start index out of bounds
	const char str2[] = "Bankai";
	unsigned int start2 = 10;
	size_t len2 = 5;
	char *result2 = ft_substr(str2, start2, len2);
	printf("Test 2: %s\n", result2);
	free(result2);

	// Test case 3: Length exceeds available characters
	const char str3[] = "Bankai";
	unsigned int start3 = 3;
	size_t len3 = 10;
	char *result3 = ft_substr(str3, start3, len3);
	printf("Test 3: %s\n", result3);
	free(result3);

	// Test case 4: Empty string
	const char str4[] = "";
	unsigned int start4 = 0;
	size_t len4 = 5;
	char *result4 = ft_substr(str4, start4, len4);
	printf("Test 4: %s\n", result4);
	free(result4);

	return (0);
}
*/
