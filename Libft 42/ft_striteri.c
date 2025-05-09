/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:17:26 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:12:10 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void caps(unsigned int index, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
    printf("Character at index %u: %c\n", index, *c);
}

int main()
{
    char str[] = "sosuke aizen";

    printf("\nOriginal string: %s\n\n", str);
    ft_striteri(str, caps);
    printf("\nModified string: %s\n\n", str);

    return 0;
}
 */