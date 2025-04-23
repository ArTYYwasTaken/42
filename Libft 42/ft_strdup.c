/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:29 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:41:29 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	This file contains the implementation of a custom string duplication
	function `ft_strdup` which mimics the behavior of the standard `strdup`
	function. It also includes helper functions to calculate string length and
	to copy strings safely.

	RETURN VALUE:
	The `ft_strdup` function returns a pointer to a newly allocated string which
	is a duplicate of the input string.
	If memory allocation fails, it returns NULL.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	arrlen;
	char	*arr;

	arrlen = ft_strlen(s) + 1;
	arr = malloc(arrlen * sizeof(char));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s, arrlen);
	return (arr);
}
/* 
// TEST CODE
int main()
{
    char *my_copy;
    char *real_copy;
    char *test_string = "Hello, World!";
    char *empty_string = "";
    char *long_string = "This is a very long string to test if (ft_)strdup
	can handle it.";

    // Test 1: Normal string
    printf("\nTest 1: Normal string\n");
    my_copy = ft_strdup(test_string);
    real_copy = strdup(test_string);

    if (my_copy && real_copy)
	{
        printf("My ft_strdup: \"%s\"\n", my_copy);
        printf("Original strdup: \"%s\"\n", real_copy);
        free(my_copy);
        free(real_copy);
    } else
        printf("Memory allocation failed.\n");

    // Test 2: Empty string
    printf("\nTest 2: Empty string\n");
    my_copy = ft_strdup(empty_string);
    real_copy = strdup(empty_string);

    if (my_copy && real_copy)
	{
        printf("My ft_strdup: \"%s\"\n", my_copy);
        printf("Original strdup: \"%s\"\n", real_copy);
        free(my_copy);
        free(real_copy);
    } else
        printf("Memory allocation failed.\n");

    // Test 3: Long string
    printf("\nTest 3: Long string\n");
    my_copy = ft_strdup(long_string);
    real_copy = strdup(long_string);

    if (my_copy && real_copy)
	{
        printf("My ft_strdup: \"%s\"\n", my_copy);
        printf("Original strdup: \"%s\"\n\n", real_copy);
        free(my_copy);
        free(real_copy);
    } else
        printf("Memory allocation failed.\n\n");
    return 0;
}
*/
