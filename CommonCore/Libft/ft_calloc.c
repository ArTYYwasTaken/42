/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:34:32 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:34:32 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	Custom implementation of the calloc function, which allocates memory for an array of nmemb elements of size bytes each and initializes all bytes in the allocated storage to zero.

	RETURN VALUE:
	Returns a pointer to the allocated memory, or NULL if the allocation fails.
*/

#include <stdio.h>
#include <stdlib.h>

// Helper function to check for overflow in multiplication
static int is_overflow(size_t nmemb, size_t size)
{
	// Check if the multiplication of nmemb and size would overflow
	return (nmemb && size > (SIZE_MAX / nmemb));
}

// Custom calloc function
void *ft_calloc(size_t nmemb, size_t size)
{
	// Check for zero elements or size, or if multiplication would overflow
	if (nmemb == 0 || size == 0 || is_overflow(nmemb, size))
		return (NULL);

	void *p;
	// Allocate memory for nmemb elements of size bytes each
	p = malloc(nmemb * size);
	if (!p) // Check if malloc failed
		return (NULL);

	// Initialize allocated memory to zero
	ft_bzero(p, nmemb * size);
	return (p); // Return pointer to allocated memory
}

/* 
// TEST CODE
int main()
{
	int *my_array;
	int *real_array;
	int num_elements = 5; // Number of elements to allocate
	int element_size = sizeof(int); // Size of each element

	// Test with your ft_calloc
	my_array = (int *)ft_calloc(num_elements, element_size);

	if (my_array != NULL) {
		printf("My ft_calloc: ");
		for (int i = 0; i < num_elements; i++) {
			printf("%d ", my_array[i]); // Print each element (should be 0)
		}
		printf("\n");
		free(my_array); // Important: free the memory!
	} else {
		printf("My ft_calloc failed to allocate memory.\n");
	}

	// Test with the real calloc
	real_array = (int *)calloc(num_elements, element_size);

	if (real_array != NULL) {
		printf("Real calloc: ");
		for (int i = 0; i < num_elements; i++) {
			printf("%d ", real_array[i]); // Print each element (should be 0)
		}
		printf("\n");
		free(real_array); // Important: free the memory!
	} else {
		printf("Real calloc failed to allocate memory.\n");
	}

	return 0;
}
*/