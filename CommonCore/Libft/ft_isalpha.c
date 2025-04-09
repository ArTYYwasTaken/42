/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:36:39 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:36:39 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_isalpha checks whether c is alphabetic or not.

	RETURN VALUE:
	Non-zero if c is alphabetic, zero if not.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/* 
// TEST CODE
int main() {
    // Test cases
    int test1 = 'A';  // Uppercase letter
    int test2 = 'z';  // Lowercase letter
    int test3 = '5';  // Digit
    int test4 = '!';  // Non-alphabetic character
    int test5 = ' ';  // Space character
    int test6 = 'm';  // Lowercase letter
    int test7 = 'Z';  // Uppercase letter

    // Testing ft_isalpha
    printf("ft_isalpha('%c') = %d\n", test1, ft_isalpha(test1));
    printf("ft_isalpha('%c') = %d\n", test2, ft_isalpha(test2));
    printf("ft_isalpha('%c') = %d\n", test3, ft_isalpha(test3));
    printf("ft_isalpha('%c') = %d\n", test4, ft_isalpha(test4));
    printf("ft_isalpha('%c') = %d\n", test5, ft_isalpha(test5));
    printf("ft_isalpha('%c') = %d\n", test6, ft_isalpha(test6));
    printf("ft_isalpha('%c') = %d\n", test7, ft_isalpha(test7));

    // Testing standard isalpha for comparison
    printf("isalpha('%c') = %d\n", test1, isalpha(test1));
    printf("isalpha('%c') = %d\n", test2, isalpha(test2));
    printf("isalpha('%c') = %d\n", test3, isalpha(test3));
    printf("isalpha('%c') = %d\n", test4, isalpha(test4));
    printf("isalpha('%c') = %d\n", test5, isalpha(test5));
    printf("isalpha('%c') = %d\n", test6, isalpha(test6));
    printf("isalpha('%c') = %d\n", test7, isalpha(test7));

    return 0;
}
*/