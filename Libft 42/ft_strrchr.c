/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:44:03 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:44:03 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_strrchr finds the last occurrence of character c in
	string str.

	PARAMETERS:
	- const char *s : The string to be searched.
	- int c : The character to be found.

	RETURN VALUE:
	A pointer to the last occurrence of c in str.
	NULL if c is not found.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
// TEST CODE
int main()
{
	char str[] = "arthur";
	char c = 'a';
	printf("\n%p\n", ft_strrchr(str, c));
	printf("\n%p\n\n", strrchr(str, c));
	return 0;
} */