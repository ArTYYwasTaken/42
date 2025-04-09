/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:17 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:39:17 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The ft_memchr function scans the initial n bytes of the memory area pointed to by s
    for the first instance of c. Both c and the bytes of the memory area pointed to by s
    are interpreted as unsigned char.

    RETURN VALUE:
    The ft_memchr function returns a pointer to the matching byte or NULL if the character
    does not occur in the given memory area.
*/

#include "libft.h"

// Function to search for the first occurrence of a character in a memory block
void *ft_memchr(const void *s, int c, size_t n)
{
    // // Check if the input pointer is NULL
    // if (s == NULL)
    //     return (NULL);

    size_t i;
    unsigned char *str;
    unsigned char ch;

    // Cast the input pointer to an unsigned char pointer for byte-wise comparison
    str = (unsigned char *)s;
    ch = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        // Check if the current byte matches the target character
        if (str[i] == ch)
            return ((void *)&str[i]); // Return a pointer to the matching byte
        i++;
    }
    return (NULL); // Return NULL if the character is not found
}
/* 
// TEST CODE
int main() {
    char my_array[] = "Hello World!";
    char search_char = 'W';

    // Test with your ft_memchr
    char *my_result = (char *)ft_memchr(my_array, search_char, sizeof(my_array));
    if (my_result != NULL) {
        printf("My ft_memchr found '%c' at: %ld\n", search_char, my_result - my_array);
    } else {
        printf("My ft_memchr didn't find '%c'\n", search_char);
    }

    // Test with the real memchr
    char *real_result = (char *)memchr(my_array, search_char, sizeof(my_array));
    if (real_result != NULL) {
        printf("Real memchr found '%c' at: %ld\n", search_char, real_result - my_array);
    } else {
        printf("Real memchr didn't find '%c'\n", search_char);
    }

    // Test with a character that's not there
    search_char = 'z';

    my_result = (char *)ft_memchr(my_array, search_char, sizeof(my_array));
    if (my_result != NULL) {
        printf("My ft_memchr found '%c' at: %ld\n", search_char, my_result - my_array);
    } else {
        printf("My ft_memchr didn't find '%c'\n", search_char);
    }

    real_result = (char *)memchr(my_array, search_char, sizeof(my_array));
    if (real_result != NULL) {
        printf("Real memchr found '%c' at: %ld\n", search_char, real_result - my_array);
    } else {
        printf("Real memchr didn't find '%c'\n", search_char);
    }
    return 0;
}
 */