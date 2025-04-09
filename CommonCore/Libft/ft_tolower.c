/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:46:33 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_tolower converts a given uppercase letter c to its
	lowercase equivalent.

	RETURN VALUE :
	The lowercase equivalent letter.
	The original character c if c is not an uppercase letter.	
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
// TEST CODE
int main()
{
	char c = 'Z';
	printf("%c\n", ft_tolower(c));
	printf("%c\n", tolower(c));
	return 0;
} */