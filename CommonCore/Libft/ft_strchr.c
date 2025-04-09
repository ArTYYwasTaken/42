/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:14 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:41:14 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_strchr finds the first occurence of character c in
	string str.

	RETURN VALUE:
	A pointer to the first occurence of c in str.
	NULL if c is not found.
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*
// TEST CODE
int main()
{
	char str[] = "arthur";
	char c = 0;
	printf("%p\n", ft_strchr(str, c));
	printf("%p\n", strchr(str, c));
	return 0;
} */