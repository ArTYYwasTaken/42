/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:37 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:39:37 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The ft_memcpy function copies n bytes from the memory area pointed to by src to the memory area pointed to by dest. 

	PARAMETERS:
	- dest: A pointer to the destination memory area where the content is to be copied.
	- src: A pointer to the source memory area from which the content is to be copied.
	- n: The number of bytes to copy from the source to the destination.

	RETURN VALUE:
	The function returns a pointer to the destination memory area (dest).
*/

#include "libft.h"

// Function to copy n bytes from src to dest
void *ft_memcpy(void *dest, const void *src, size_t n)
{
    // // Check for NULL pointers
    // if (dest == NULL || src == NULL)
    //     return (NULL);

    size_t i; // Loop counter
    unsigned char *dp; // Destination pointer cast to unsigned char
    unsigned char *sp; // Source pointer cast to unsigned char

    dp = dest;
    sp = (unsigned char *)src;  // Cast src to unsigned char pointer
    i = 0;
    // Copy each byte from src to dest
    while (i < n)
    {
        dp[i] = sp[i];
        i++;
    }
    return (dest); // Return the destination pointer
}
/* 
// TEST CODE
int main() {
    int my_source_array[5] = {10, 20, 30, 40, 50}; // Source array for custom memcpy
    int my_dest_array[5]; // Destination array for custom memcpy

    int real_source_array[5] = {10, 20, 30, 40, 50}; // Source array for standard memcpy
    int real_dest_array[5]; // Destination array for standard memcpy

	// My memcpy function
    printf("My memcpy:\n");
    printf("Source array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", my_source_array[i]); // Print source array
    }
    printf("\n");

    ft_memcpy(my_dest_array, my_source_array, sizeof(my_source_array)); // Copy using custom memcpy

    printf("Destination array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", my_dest_array[i]); // Print destination array
    }
    printf("\n\n");

	// Original memcpy function
    printf("Real memcpy:\n");
    printf("Source array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", real_source_array[i]); // Print source array
    }
    printf("\n");

    memcpy(real_dest_array, real_source_array, sizeof(real_source_array)); // Copy using standard memcpy

    printf("Destination array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", real_dest_array[i]); // Print destination array
    }
    printf("\n");

    return 0;
<<<<<<< HEAD
}
*/
=======
}*/
>>>>>>> fd11879e43bfe78cc59d6732cb8b48884b75a91b
