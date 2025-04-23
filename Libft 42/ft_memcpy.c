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
	The ft_memcpy function copies n bytes from the memory area pointed to by src
	to the memory area pointed to by dest. 

	PARAMETERS:
	- dest: A pointer to the destination memory area where the content is to be
	copied.
	- src: A pointer to the source memory area from which the content is to be
	copied.
	- n: The number of bytes to copy from the source to the destination.

	RETURN VALUE:
	The function returns a pointer to the destination memory area (dest).
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	if (!n || dest == src)
		return (dest);
	dp = dest;
	sp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}
/* 
// TEST CODE
int main()
{
    int my_source_array[5] = {10, 20, 30, 40, 50};
    int my_dest_array[5];

    int real_source_array[5] = {10, 20, 30, 40, 50};
    int real_dest_array[5];

	// My memcpy function
    printf("\n---//My memcpy//---\n");
    printf("Source array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", my_source_array[i]);
    printf("\n");

    ft_memcpy(my_dest_array, my_source_array, sizeof(my_source_array));

    printf("Destination array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", my_dest_array[i]);
    printf("\n");

	// Original memcpy function
    printf("\n---//Original memcpy//---\n");
    printf("Source array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", real_source_array[i]);
    printf("\n");

    memcpy(real_dest_array, real_source_array, sizeof(real_source_array));

    printf("Destination array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", real_dest_array[i]);
    printf("\n\n");

    return 0;
}
 */