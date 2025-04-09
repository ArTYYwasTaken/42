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

int	ft_isalpha (int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/* 
// TEST CODE
int main()
{
	int c = 'h';
	int d = '1';

	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(d));
	printf("%d\n", isalpha(d));
	return 0;
} */