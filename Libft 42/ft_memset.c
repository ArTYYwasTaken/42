/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:52 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:39:52 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_memset() function fills the first n bytes of the memory area pointed
	to by s with the constant byte c.

    PARAMETERS:
	- void *s: Pointer to the memory area to be filled.
	- int c: The value to be set (converted to an unsigned char).
	- size_t n: The number of bytes to be set to the value.

    RETURN VALUE:
	The ft_memset() function returns a pointer to the memory area s.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	value;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
		ptr[i++] = value;
	return (s);
}
/* 
// TEST CODE
int main()
{
    char my_array[10];
	
	// My function
    ft_memset(my_array, 'A', 10);
	
    printf("\nArray after ft_memset: ");
    for (int i = 0; i < 10; i++)
		printf("%c ", my_array[i]);
    printf("\n");
	
    ft_memset(my_array, 0, 10);
	
    printf("Array after ft_memset with 0: ");
    for (int i = 0; i < 10; i++)
		printf("%d ", my_array[i]);
    printf("\n");
	
	memset(my_array, 'A', 10);

	printf("\nArray after memset: ");
	for (int i = 0; i < 10; i++)
		printf("%c ", my_array[i]);
	printf("\n");

	memset(my_array, 0, 10);

	printf("Array after memset with 0: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", my_array[i]);
	printf("\n\n");
	
    return 0;
}
*/
