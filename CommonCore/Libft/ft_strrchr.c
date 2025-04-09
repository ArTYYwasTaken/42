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
	DESCRIPTION :
	The function ft_strrchr finds the last occurrence of character c in
	string str.

	RETURN VALUE :
	A pointer to the last occurrence of c in str.
	NULL if c is not found.
*/

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		i;
	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
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
	printf("%p\n", ft_strrchr(str, c));
	printf("%p\n", strrchr(str, c));
	return 0;
} */