/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:36:22 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:36:22 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The function ft_isalnum checks whether the value of 'c' is alphanumeric.
    Alphanumeric means it's either a letter (a-z or A-Z) or a number (0-9).

    RETURN VALUE:
    Non-zero (specifically, the value of 'c') if 'c' is alphanumeric, zero if not.
*/

#include "libft.h"

int ft_isalnum(int c)
{
    // Check if 'c' is a lowercase letter (a to z).
    if (c >= 'a' && c <= 'z')
        return (1); // If yes, return the value of 'c' (non-zero).

    // Check if 'c' is an uppercase letter (A to Z).
    if (c >= 'A' && c <= 'Z')
        return (1); // If yes, return the value of 'c' (non-zero).

    // Check if 'c' is a digit (0 to 9).
    if (c >= '0' && c <= '9')
        return (1); // If yes, return the value of 'c' (non-zero).

    // If 'c' is not a letter or a digit, return zero.
    return (0);
}
/* 
// TEST CODE
int main()
{
	int c = 'A';
	int d = '$';

	printf("%d\n", ft_isalnum(c));
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", isalnum(d));
	return 0;
} */