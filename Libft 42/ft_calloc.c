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
	Custom implementation of the calloc function, which allocates memory for an
	array of nmemb elements of size bytes each and initializes all bytes in the
	allocated storage to zero.

	RETURN VALUE:
	Returns a pointer to the allocated memory, or NULL if the allocation fails.
*/

#include "libft.h"

// Custom calloc function
void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (!num || !size)
		return (ft_strdup(""));
	if (num > ((size_t) - 1) / size)
		return (NULL);
	else
		p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, num * size);
	return (p);
}
/* 
// TEST CODE
int main()
{
	int *my_array;
	int *real_array;
	int num = 5;
	int size = sizeof(int);

	my_array = ft_calloc(num, size);

	if (my_array)
	{
		printf("\nMy ft_calloc: ");
		for (int i = 0; i < num; i++)
			printf("%d ", my_array[i]);
		printf("\n");
		free(my_array);
	}
	else
		printf("My ft_calloc failed to allocate memory.\n");

	real_array = (int *)calloc(num, size);

	if (real_array)
	{
		printf("\nOriginal calloc: ");
		for (int i = 0; i < num; i++)
			printf("%d ", real_array[i]);
		printf("\n\n");
		free(real_array);
	}
	else
		printf("Real calloc failed to allocate memory.\n");
	return 0;
}
*/
