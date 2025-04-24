/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:17:26 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 20:27:18 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The ft_striteri() function applies the function f to each character of the
    string s, passing its index as the first argument. Each character is passed
    by address to f to be modified if necessary.

    PARAMETERS:
    - char *s: The string to be iterated over.
    - void (*f)(unsigned int, char*): The function to be applied to each
      character of the string. It takes an unsigned int (the index) and a char*
      (the character at that index).

    RETURN VALUE:
    None.
    The function modifies the string s in place and does not return a value.
*/

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
// TEST CODE
void example_function(unsigned int index, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
    printf("Character at index %u: %c\n", index, *c);
}

int main()
{
    char str[] = "sosuke aizen";

    printf("\nOriginal string: %s\n\n", str);
    ft_striteri(str, example_function);
    printf("\nModified string: %s\n\n", str);

    return 0;
}
 */