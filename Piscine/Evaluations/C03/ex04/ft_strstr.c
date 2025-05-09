/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinto-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:31:24 by jpinto-r          #+#    #+#             */
/*   Updated: 2025/03/18 18:43:03 by jpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

	if (str == NULL || to_find == NULL)
		return (NULL);
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		s = str;
		f = to_find;
		while (*s == *f && *f != '\0')
		{
			s++;
			f++;
		}
		if (*f == '\0')
			return (str);
		str++;
	}
	return (NULL);
}
/*
int main() {
    char str[] = "Esta é uma string de teste.";
    char to_find[] = "strong";
    char *result = ft_strstr(str, to_find);
    if (result != NULL) {
        printf("Substring encontrada: %s\n", result);
    } else {
        printf("Substring não encontrada.\n");
    }
    return 0;
}*/
