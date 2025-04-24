/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:44:23 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:44:23 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The ft_strtrim() function allocates sufficient memory for a new string,
    which is the result of the concatenation of s1 and s2. It trims the
    characters specified in the set from both ends of the string s1.

    PARAMETERS:
    - char const *s1: The string to be trimmed.
    - char const *set: The set of characters to be trimmed from both ends of s1.

    RETURN VALUE:
    The ft_strtrim() function returns a pointer to the newly allocated string,
    or NULL if the allocation fails.
    If s1 is NULL or set is NULL, it returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new = malloc((end - start + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], end - start + 1);
	return (new);
}
/* 
// TEST CODE
int main() {
    char *result;

    // Test case 1: Trim spaces from both ends
    result = ft_strtrim("   Hello, World!   ", " ");
    printf("\nTest 1: '%s'\n", result);
    free(result);

    // Test case 2: Trim specific characters
    result = ft_strtrim("xxHello, World!xx", "x");
    printf("Test 2: '%s'\n", result);
    free(result);

    // Test case 3: No characters to trim
    result = ft_strtrim("Hello, World!", " ");
    printf("Test 3: '%s'\n", result);
    free(result);

    // Test case 4: Empty string
    result = ft_strtrim("", " ");
    printf("Test 4: '%s'\n", result);
    free(result);

    // Test case 5: Trim all characters
    result = ft_strtrim("xxxx", "x");
    printf("Test 5: '%s'\n\n", result);
    free(result);

    return 0;
}
*/
