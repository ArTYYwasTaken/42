/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinto-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:23:30 by jpinto-r          #+#    #+#             */
/*   Updated: 2025/03/18 18:25:29 by jpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "Hemlo";
    char str4[] = "World";

    printf("Comparando \"%s\" e \"%s\": 
    %d\n", str1, str2, ft_strcmp(str1, str2));
// Deve imprimir 0
    printf("Comparando \"%s\" e \"%s\": 
    %d\n", str1, str3, ft_strcmp(str1, str3));
// Deve imprimir um valor negativo
    printf("Comparando \"%s\" e \"%s\": 
    %d\n", str1, str4, ft_strcmp(str1, str4));
// Deve imprimir um valor negativo
    printf("Comparando \"%s\" e \"%s\": 
    %d\n", str4, str1, ft_strcmp(str4, str1));
// Deve imprimir um valor positivo

    return 0;
}*/
