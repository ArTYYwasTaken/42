/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:38:18 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:38:18 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_isprint checks whether c is a printable character or not.

	RETURN VALUE:
	Non-zero if c is printable, zero if not.
*/

#include "libft.h"

int	ft_isprint (int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main()
{
    int test1 = 32;   // Space character (printable)
    int test2 = 33;   // '!' character (printable)
    int test3 = 126;  // '~' character (printable)
    int test4 = 127;  // DEL character (non-printable)
    int test5 = 31;   // Non-printable character
    int test6 = 'A';  // Printable character
    int test7 = '\n'; // Newline character (non-printable)

    // Testing my isprint
	printf("\n---//My issprint//---\n\n");
    printf("ft_isprint(%d) = %d\n", test1, ft_isprint(test1));
    printf("ft_isprint(%d) = %d\n", test2, ft_isprint(test2));
    printf("ft_isprint(%d) = %d\n", test3, ft_isprint(test3));
    printf("ft_isprint(%d) = %d\n", test4, ft_isprint(test4));
    printf("ft_isprint(%d) = %d\n", test5, ft_isprint(test5));
    printf("ft_isprint('%c') = %d\n", test6, ft_isprint(test6));
    printf("ft_isprint('\\n') = %d\n", ft_isprint(test7));

    // Testing my isprint
	printf("\n---//Original isprint//---\n\n");
    printf("isprint(%d) = %d\n", test1, isprint(test1));
    printf("isprint(%d) = %d\n", test2, isprint(test2));
    printf("isprint(%d) = %d\n", test3, isprint(test3));
    printf("isprint(%d) = %d\n", test4, isprint(test4));
    printf("isprint(%d) = %d\n", test5, isprint(test5));
    printf("isprint('%c') = %d\n", test6, isprint(test6));
    printf("isprint('\\n') = %d\n", isprint(test7));

    return 0;
}
*/
