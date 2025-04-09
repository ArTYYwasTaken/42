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
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
/*
// TEST CODE
int main()
{
	int c = 33;
	int d = 127;

	printf("%d\n", ft_isprint(c));
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(d));
	printf("%d\n", isprint(d));
	return 0;
} */