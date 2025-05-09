/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:40 by klino-an          #+#    #+#             */
/*   Updated: 2025/03/17 14:48:44 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	while (src[count] != '\0')
		count++;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (size > 0)
		dest[i] = '\0';
	return (count);
}

int main()
{
	char src[] = "oiiiiii";
	char dest[] = "hello";
	int size = 8;
	printf("%s \n", dest);
	printf("%d \n", ft_strlcpy(dest, src, size));
	printf("%d \n", strlcpy(dest, src, size));
	printf("%s \n", dest);
}

