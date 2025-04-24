/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:36:49 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:36:49 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_isascii checks whether c is an ascii character or not.

	RESULT VALUE:
	Non-zero if c is ascii, zero if not.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/* 
int main()
{
	int test1 = 68;
	int test2 = 128;
	int test3 = 0;
	int test4 = 127;
	int test5 = 65;
	int test6 = -1;
	int test7 = 255;

	// Testing my isascii
	printf("\n---//My isascii//---\n\n");
	printf("ft_isascii(%d) = %d\n", test1, ft_isascii(test1));
	printf("ft_isascii(%d) = %d\n", test2, ft_isascii(test2));
	printf("ft_isascii(%d) = %d\n", test3, ft_isascii(test3));
	printf("ft_isascii(%d) = %d\n", test4, ft_isascii(test4));
	printf("ft_isascii(%d) = %d\n", test5, ft_isascii(test5));
	printf("ft_isascii(%d) = %d\n", test6, ft_isascii(test6));
	printf("ft_isascii(%d) = %d\n", test7, ft_isascii(test7));

	// Testing original isascii
	printf("\n---//Original isascii//---\n\n");
	printf("isascii(%d) = %d\n", test1, isascii(test1));
	printf("isascii(%d) = %d\n", test2, isascii(test2));
	printf("isascii(%d) = %d\n", test3, isascii(test3));
	printf("isascii(%d) = %d\n", test4, isascii(test4));
	printf("isascii(%d) = %d\n", test5, isascii(test5));
	printf("isascii(%d) = %d\n", test6, isascii(test6));
	printf("isascii(%d) = %d\n\n", test7, isascii(test7));

	return 0;
}
*/
