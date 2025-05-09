/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinto-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:25:47 by jpinto-r          #+#    #+#             */
/*   Updated: 2025/03/18 18:28:22 by jpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}
/*
int	main()
{
	char str1[] = "Hello";
	char str1[] = "Hellz";

	printf("compara os primeiros 4 caracteres %d\n", ft_strncmp(str1, str2, 4));
	printf("compara os primeiros 5 caracteres %d\n", ft_strncmp(str1, str2, 5));

	return (0);
}
*/
