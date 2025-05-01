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

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
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
int main()
{
    char str[] = "arthur";
    char c = 't';
    char *res_my_strchr = ft_strchr(str, c);
    char *res_strchr = strchr(str, c);

    printf("\nft_strchr: %p, result: %s\n", res_my_strchr, res_my_strchr);
    printf("\nstrchr: %p, result: %s\n\n", res_strchr, res_strchr);

    return 0;
}
*/
