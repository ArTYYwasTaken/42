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

int	ft_atoi(const char *str)
{
    int num;    // The number that will be built from the string.
    int sign;  // The sign of the number (+1 for positive, -1 for negative).
    size_t i;     // A counter to keep track of our position in the string.

    num = 0;      // Start with the number at zero.
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
    while (str[i] && ft_isdigit((int)str[i]))
    {
        // '0' is 48 in ASCII, so we subtract 48 to get the digit's value.
        num = num * 10 + (str[i] - 48);
        i++; // Move to the next digit.
    }

    // Return the number with the correct sign.
    return (num * sign);
}
/* 
// TEST CODE
int main() {
    // Test cases
    char *test1 = " --1234a5";
    char *test2 = "42";
    char *test3 = "   +2147483647";
    char *test4 = "   -2147483648";
    char *test5 = "   0";
    char *test6 = "   +0";
    char *test7 = "   -0";
    char *test8 = "   +000123";
    char *test9 = "   -000123";
    char *test10 = "   123abc456";

    // Testing ft_atoi
    printf("ft_atoi(\"%s\") = %d\n", test1, ft_atoi(test1));
    printf("ft_atoi(\"%s\") = %d\n", test2, ft_atoi(test2));
    printf("ft_atoi(\"%s\") = %d\n", test3, ft_atoi(test3));
    printf("ft_atoi(\"%s\") = %d\n", test4, ft_atoi(test4));
    printf("ft_atoi(\"%s\") = %d\n", test5, ft_atoi(test5));
    printf("ft_atoi(\"%s\") = %d\n", test6, ft_atoi(test6));
    printf("ft_atoi(\"%s\") = %d\n", test7, ft_atoi(test7));
    printf("ft_atoi(\"%s\") = %d\n", test8, ft_atoi(test8));
    printf("ft_atoi(\"%s\") = %d\n", test9, ft_atoi(test9));
    printf("ft_atoi(\"%s\") = %d\n", test10, ft_atoi(test10));

    // Testing standard atoi for comparison
    printf("atoi(\"%s\") = %d\n", test1, atoi(test1));
    printf("atoi(\"%s\") = %d\n", test2, atoi(test2));
    printf("atoi(\"%s\") = %d\n", test3, atoi(test3));
    printf("atoi(\"%s\") = %d\n", test4, atoi(test4));
    printf("atoi(\"%s\") = %d\n", test5, atoi(test5));
    printf("atoi(\"%s\") = %d\n", test6, atoi(test6));
    printf("atoi(\"%s\") = %d\n", test7, atoi(test7));
    printf("atoi(\"%s\") = %d\n", test8, atoi(test8));
    printf("atoi(\"%s\") = %d\n", test9, atoi(test9));
    printf("atoi(\"%s\") = %d\n", test10, atoi(test10));

    return 0;
}
*/