/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:42:48 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:42:48 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	if(!s1 || !s2)
		return (NULL);

	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	ptr = malloc((s1_len + s2_len + 1) * sizeof(char));
	if(!ptr)
		return (NULL);

    ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	// while(s1[i])
	// {
	// 	ptr[i] = s1[i];
	// 	i++;
	// }

	// while(s2[j])
	// {
	// 	ptr[i + j] = s2[j];
	// 	j++;
	// }
	// ptr[i + j] = '\0';
	return (ptr);
}
/* 
// TEST CODE
int main()
{
    char *result;

    // Test 1: Normal strings
    printf("Test 1: Normal strings\n");
    result = ft_strjoin("Hello, ", "World!");
    if (result) {
        printf("Result: \"%s\"\n", result);
        free(result); // Don't forget to free the memory!
    } else {
        printf("Memory allocation failed.\n");
    }

    // Test 2: Empty string s1
    printf("\nTest 2: Empty string s1\n");
    result = ft_strjoin("", "World!");
    if (result) {
        printf("Result: \"%s\"\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    // Test 3: Empty string s2
    printf("\nTest 3: Empty string s2\n");
    result = ft_strjoin("Hello, ", "");
    if (result) {
        printf("Result: \"%s\"\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    // Test 4: Both empty strings
    printf("\nTest 4: Both empty strings\n");
    result = ft_strjoin("", "");
    if (result) {
        printf("Result: \"%s\"\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    // Test 5: NULL s1
    printf("\nTest 5: NULL s1\n");
    result = ft_strjoin(NULL, "World!");
    if (result) {
        printf("Result: \"%s\"\n", result);
        free(result);
    } else {
        printf("Result: NULL\n");
    }

    // Test 6: NULL s2
    printf("\nTest 6: NULL s2\n");
    result = ft_strjoin("Hello,", NULL);
    if (result) {
        printf("Result: \"%s\"\n", result);
        free(result);
    } else {
        printf("Result: NULL\n");
    }

    return 0;
}
*/