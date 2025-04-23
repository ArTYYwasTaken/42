/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:43:43 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:43:43 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_strncmp compares the first n bytes of the given strings
	s1 and s2.

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if one of the first
	n bytes of s1 is found to be less than, to match, or to be greater than 
	s2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/* 
// TEST CODE
int main()
{
	char s1[] = "Arthur";
	char s2[] = "Arthur";
	int n = 6;
	printf("\n%d\n", ft_strncmp(s1, s2, n));
	printf("\n%d\n\n", strncmp(s1, s2, n));
}
*/