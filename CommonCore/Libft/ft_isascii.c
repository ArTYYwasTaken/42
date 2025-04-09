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

int	ft_isascii (int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/* 
// TEST CODE
int main()
{
	int c = 68;
	int d = 128;

	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(d));
	printf("%d\n", isascii(d));
	return 0;
} */
