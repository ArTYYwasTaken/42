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

#include "libft.h"

// Custom calloc function
void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	// Check for zero elements or size
	if (!num || !size)
        return(ft_strdup(""));
    if(num > ((size_t) - 1) / size)
        return (NULL);
    else
	// Allocate memory for num elements of size bytes each
	    p = malloc(num * size);
	if (!p) // Check if malloc failed
		return (NULL);
	// Initialize allocated memory to zero
	ft_bzero(p, num * size);
	return (p); // Return pointer to allocated memory
}
/* 
// TEST CODE
int main()
{
	int *my_array;
	int *real_array;
	int num = 5; // Number of elements to allocate
	int size = sizeof(int); // Size of each element

	// Test with your ft_calloc
	my_array = ft_calloc(num, size);

	if (my_array != NULL)
	{
		printf("\nMy ft_calloc: ");
		for (int i = 0; i < num; i++)
			printf("%d ", my_array[i]);
		printf("\n");
		free(my_array);
	} else
		printf("My ft_calloc failed to allocate memory.\n");

	// Test with the original calloc
	real_array = (int *)calloc(num, size);

	if (real_array != NULL)
	{
		printf("\nOriginal calloc: ");
		for (int i = 0; i < num; i++)
			printf("%d ", real_array[i]);
		printf("\n\n");
		free(real_array);
	} else
		printf("Real calloc failed to allocate memory.\n");

	return 0;
}
*/
