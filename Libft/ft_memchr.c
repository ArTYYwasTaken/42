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

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/* 
int main()
{
    char my_array[] = "Sosuke Aizen";
    char search_char = 'k';

    char *my_result = ft_memchr(my_array, search_char, sizeof(my_array));
    if (my_result)
	{
        printf("\nMy ft_memchr found '%c' at: %ld\n", search_char,
		my_result - my_array);
    } else
        printf("\nMy ft_memchr didn't find '%c'\n", search_char);

    char *real_result = memchr(my_array, search_char, sizeof(my_array));
    if (real_result)
	{
        printf("Original memchr found '%c' at: %ld\n", search_char,
		real_result - my_array);
    }
	else
        printf("Original memchr didn't find '%c'\n", search_char);

    search_char = 'x';

    my_result = ft_memchr(my_array, search_char, sizeof(my_array));
    if (my_result)
	{
        printf("\nMy ft_memchr found '%c' at: %ld\n", search_char,
		my_result - my_array);
    }
	else
        printf("\nMy ft_memchr didn't find '%c'\n", search_char);

    real_result = memchr(my_array, search_char, sizeof(my_array));
    if (real_result)
	{
        printf("Original memchr found '%c' at: %ld\n", search_char,
		real_result - my_array);
    }
	else
        printf("Original memchr didn't find '%c'\n", search_char);
	printf("\n");
    return 0;
}
*/