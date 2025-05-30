/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:15:27 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:10:38 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* 
char caps_even(unsigned int i, char c)
{
    if (i % 2 == 0)
	{
        if (c >= 'a' && c <= 'z')
            return c - 32;
    }
	else
	{
        if (c >= 'A' && c <= 'Z')
            return c + 32;
    }
    return c;
}

int main()
{
    char *original = "sosuke aizen";
    char *result = ft_strmapi(original, caps_even);

    if (result)
	{
        printf("\nOriginal: %s\n", original);
        printf("New: %s\n\n", result);
        free(result);
    }
	else
        printf("Error: Memory allocation failed.\n\n");
    return 0;
}
 */