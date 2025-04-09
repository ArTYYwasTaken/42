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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
// TEST CODE
int main()
{
    char str[] = "arthur";
    char c = 't';
    char *result_ft_strchr = ft_strchr(str, c);
    char *result_strchr = strchr(str, c);

    printf("ft_strchr: %p, result: %s\n", result_ft_strchr, result_ft_strchr);
    printf("strchr: %p, result: %s\n", result_strchr, result_strchr);

    return 0;
}
*/