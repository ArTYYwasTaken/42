/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:43:53 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:43:53 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_strnstr searches the first n bytes of the given string
	s1 for the first occurence of the full string s2.
	Characters that appear after \0 are not searched.

	RETURN VALUE :
	A pointer to the first character of the first occurrence of s2.
	A pointer to s1 if s2 is empty.
	NULL if s2 occurs nowhere in s1.
*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while ((i + j) < n && s1[i + j] && s2[j] && s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
/*
// TEST CODE
int main()
{
	char s1[] = "Kaio bue fofo";
	char s2[] = "bue";
	size_t n = 6;
	printf("%c\n", ft_strnstr(s1, s2, n));
}
*/