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

int	ft_isdigit (int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* 
// TEST CODE
int main()
{
	int c = '0';
	int d = 'h';

	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(d));
	printf("%d\n", isdigit(d));
	return 0;
} */