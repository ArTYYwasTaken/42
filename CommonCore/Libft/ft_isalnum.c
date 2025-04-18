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

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
/* 
// TEST CODE
int main()
{
    int test1 = 'A';
    int test2 = 'z';
    int test3 = '5';
    int test4 = '!';
    int test5 = ' ';
    int test6 = '0';
    int test7 = '9';

    // Testing my isalnum
	printf("---//My isalnum//---\n\n");
    printf("ft_isalnum('%c') = %d\n", test1, ft_isalnum(test1));
    printf("ft_isalnum('%c') = %d\n", test2, ft_isalnum(test2));
    printf("ft_isalnum('%c') = %d\n", test3, ft_isalnum(test3));
    printf("ft_isalnum('%c') = %d\n", test4, ft_isalnum(test4));
    printf("ft_isalnum('%c') = %d\n", test5, ft_isalnum(test5));
    printf("ft_isalnum('%c') = %d\n", test6, ft_isalnum(test6));
    printf("ft_isalnum('%c') = %d\n", test7, ft_isalnum(test7));

    // Testing original isalnum
	printf("\n---//Original isalnum//---\n\n");
    printf("isalnum('%c') = %d\n", test1, isalnum(test1));
    printf("isalnum('%c') = %d\n", test2, isalnum(test2));
    printf("isalnum('%c') = %d\n", test3, isalnum(test3));
    printf("isalnum('%c') = %d\n", test4, isalnum(test4));
    printf("isalnum('%c') = %d\n", test5, isalnum(test5));
    printf("isalnum('%c') = %d\n", test6, isalnum(test6));
    printf("isalnum('%c') = %d\n\n", test7, isalnum(test7));

    return 0;
}
*/
