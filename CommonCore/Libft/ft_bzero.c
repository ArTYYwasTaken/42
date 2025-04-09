/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:34:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:34:28 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The `ft_bzero` function sets the first `n` bytes of the memory area
    pointed to by `s` to zero.

    PARAMETERS:
    - `s`: A pointer to the memory area to be filled with zeros.
    - `n`: The number of bytes to be set to zero.

    RETURN VALUE:
    This function does not return a value.
*/

#include "libft.h"

// Function to set the first `n` bytes of the memory area pointed to by `s` to zero
void ft_bzero(void *s, size_t n)
{
    // Check if the pointer `s` is NULL to prevent segmentation faults
    if (s == NULL)
        return;

    size_t i;  // Declare a variable for iteration
    unsigned char *ptr;  // Declare a pointer to iterate over the memory area

    ptr = (unsigned char *)s;  // Cast the void pointer `s` to an unsigned char pointer
    i = 0;  // Initialize the iteration variable
    while (i < n)  // Loop through the memory area
    {
        ptr[i] = 0;  // Set each byte to zero
        i++;  // Increment the iteration variable
    }
}

/* 
// TEST CODE
int main() {
    int my_array[5];  // Declare an integer array of size 5
    int original_array[5];  // Declare another integer array for comparison

    // Initialize the `my_array` with values
    my_array[0] = 10;
    my_array[1] = 20;
    my_array[2] = 30;
    my_array[3] = 40;
    my_array[4] = 50;

    // Print the array before using `ft_bzero`
    printf("Array before ft_bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", my_array[i]);
    printf("\n");
    
    // Use `ft_bzero` to set all elements of `my_array` to zero
    ft_bzero(my_array, sizeof(my_array));
    
    // Print the array after using `ft_bzero`
    printf("Array after ft_bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", my_array[i]);
    printf("\n");
    
    // Copy `my_array` to `original_array` for comparison
    memcpy(original_array, my_array, sizeof(my_array));

    // Print the `original_array` before using the standard `bzero`
    printf("Array before real bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", original_array[i]);
    printf("\n");

    // Use the standard `bzero` to set all elements of `original_array` to zero
    bzero(original_array, sizeof(original_array));

    // Print the `original_array` after using the standard `bzero`
    printf("Array after real bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", original_array[i]);
    printf("\n");

    return 0;  // Return 0 to indicate successful execution
}
*/