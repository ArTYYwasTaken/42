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

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while ((i + j) < len && big[i + j] && little[j]
			&& big[i + j] == little[j])
		{
			j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char s1[] = "Kaio bue fofo";
	char s2[] = "bue";
	size_t n = 6;
	printf("\n%c\n\n", ft_strnstr(s1, s2, n));
}
*/