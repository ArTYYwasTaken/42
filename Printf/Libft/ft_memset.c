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
int main()
{
    char my_array[10];
	
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
