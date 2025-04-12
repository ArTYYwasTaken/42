/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:43:33 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:43:33 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
	The function ft_strlen measures the length of the given string str,
	excluding the terminating \0 character.

	RETURN VALUE:
	The number of bytes in the string str.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
/* 
// TEST CODE
int main()
{
	char str[] = "Kaio";
	printf("%zu\n", ft_strlen(str));
	printf("%zu\n", strlen(str));
	return 0;
} */