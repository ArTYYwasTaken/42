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

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/* 
int main()
{
    int my_array[] = {10, 20, 30, 40, 50};
    int original_array[]= {10, 20, 30, 40, 50};

    printf("\nArray before ft_bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", my_array[i]);
    printf("\n");
    
    ft_bzero(my_array, sizeof(my_array));
    
    printf("Array after ft_bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", my_array[i]);
    printf("\n\n");

    printf("Array before original bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", original_array[i]);
    printf("\n");

    bzero(original_array, sizeof(original_array));

    printf("Array after original bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", original_array[i]);
    printf("\n\n");

    return 0;
}
*/