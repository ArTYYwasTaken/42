/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:12 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/09 14:46:12 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;

	i = 0;
	str_len = ft_strlen(s);
	if(!s)
		return (NULL);
	if(start >= str_len)
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if(len > str_len - start)
    	len = str_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if(!ptr)
		return (NULL);
	while(i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);       
}
/* 
// TEST CODE
int main()
{
	const char str[] = "Bankai";
	unsigned int start = 1;
	size_t len = 9;
	printf("%s\n", ft_substr(str, start, len));
	return 0;
} */