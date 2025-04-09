/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:38:05 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:38:05 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_isdigit checks whether c is a digit character or not.

	RETURN VALUE:
	Non-zero if c is a digit, zero if not.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* 
// TEST CODE
int main() {
    // Test cases
    int test1 = '0';  // Digit
    int test2 = '9';  // Digit
    int test3 = '5';  // Digit
    int test4 = 'a';  // Non-digit
    int test5 = 'Z';  // Non-digit
    int test6 = '!';  // Non-digit
    int test7 = ' ';  // Space character

    // Testing ft_isdigit
    printf("ft_isdigit('%c') = %d\n", test1, ft_isdigit(test1));
    printf("ft_isdigit('%c') = %d\n", test2, ft_isdigit(test2));
    printf("ft_isdigit('%c') = %d\n", test3, ft_isdigit(test3));
    printf("ft_isdigit('%c') = %d\n", test4, ft_isdigit(test4));
    printf("ft_isdigit('%c') = %d\n", test5, ft_isdigit(test5));
    printf("ft_isdigit('%c') = %d\n", test6, ft_isdigit(test6));
    printf("ft_isdigit('%c') = %d\n", test7, ft_isdigit(test7));

    // Testing standard isdigit for comparison
    printf("isdigit('%c') = %d\n", test1, isdigit(test1));
    printf("isdigit('%c') = %d\n", test2, isdigit(test2));
    printf("isdigit('%c') = %d\n", test3, isdigit(test3));
    printf("isdigit('%c') = %d\n", test4, isdigit(test4));
    printf("isdigit('%c') = %d\n", test5, isdigit(test5));
    printf("isdigit('%c') = %d\n", test6, isdigit(test6));
    printf("isdigit('%c') = %d\n", test7, isdigit(test7));

    return 0;
}
*/