/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:34:20 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:34:20 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The function ft_atoi converts a string (a sequence of characters) into an integer (a whole number).
    It handles spaces, tabs, newlines, plus and minus signs, and digits.

    RETURN VALUE:
    The converted integer.
*/

#include "libft.h"

int ft_atoi(const char *str)
{
    int n;    // The number that will be built from the string.
    int sign;  // The sign of the number (+1 for positive, -1 for negative).
    int i;     // A counter to keep track of our position in the string.

    n = 0;      // Start with the number at zero.
    sign = 1;    // Assume the number is positive to start.
    i = 0;       // Start at the beginning of the string.

    // Skip any leading whitespace characters (spaces, tabs, newlines, etc.).
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;

    // Check if there's a plus or minus sign.
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1; // If it's a minus, change the sign to negative.
        i++;            // Move to the next character.
    }

    // Convert the digits to a number.
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        // '0' is 48 in ASCII, so we subtract 48 to get the digit's value.
        n = n * 10 + (str[i] - 48);
        i++; // Move to the next digit.
    }

    // Return the number with the correct sign.
    return (n * sign);
}
/*
// TEST CODE
int main()
{
	char str[] = " --1234a5";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
} */