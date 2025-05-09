/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:29:39 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/18 19:29:40 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *arr, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;

	len = ft_strlen(src) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		ft_strcpy(str, src);
	return (str);
}
/* 
int main()
{
	char src[] = "Itachi";
	char *dup;
	dup = ft_strdup(src);

	printf("%s\n", dup);
} */
