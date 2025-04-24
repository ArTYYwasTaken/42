/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:06 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/24 21:24:21 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_split() function splits a string into an array of strings based on a
	delimiter character. It allocates memory for the matrizing array and each
	string.
	The last element of the array is set to NULL.

    PARAMETERS:
	- char const *s: The string to be split.
	- char c: The delimiter character used to split the string.

    RETURN VALUE:
	The ft_split() function returns a pointer to the array of strings. If the
	allocation fails or if the input string is NULL, it returns NULL.
*/

#include "libft.h"

static void	free_memory(char **matriz, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	split_matriz(char **matriz, char const *s, size_t count, char c)
{
	size_t	i;
	size_t	arr_index;
	size_t	mat_index;

	i = 0;
	mat_index = 0;
	while (mat_index < count)
	{
		arr_index = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			arr_index++;
			i++;
		}
		matriz[mat_index] = (char *)malloc((arr_index + 1) * sizeof(char));
		if (!matriz[mat_index])
		{
			free_memory(matriz, mat_index);
			return (0);
		}
		mat_index++;
	}
	return (1);
}

static void	fill_array(char **matriz, char const *s, size_t count, char c)
{
	size_t	i;
	size_t	arr_index;
	size_t	mat_index;

	i = 0;
	mat_index = 0;
	while (mat_index < count)
	{
		arr_index = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			matriz[mat_index][arr_index++] = s[i++];
		matriz[mat_index][arr_index] = '\0';
		mat_index++;
	}
	matriz[mat_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	total_words;
	char	**matriz;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	matriz = malloc((total_words + 1) * sizeof(char *));
	if (!matriz)
		return (NULL);
	if (!split_matriz(matriz, s, total_words, c))
		return (NULL);
	fill_array(matriz, s, total_words, c);
	return (matriz);
}
/* 
int main()
{
    char **matriz;
	char *str = "Kaio,bué,paia";
    char delimiter = ',';
    size_t i = 0;

    matriz = ft_split(str, delimiter);
    if (!matriz)
    {
        printf("Error: ft_split returned NULL\n");
        return 1;
    }

    printf("\nSplitting string: \"%s\"", str);
    printf("\nDelimiter: '%c'\n", delimiter);
    printf("\n");
    while (matriz[i])
    {
        printf("Segment %d: %s\n", i, matriz[i]);
        free(matriz[i]);
        i++;
    }
    free(matriz);
    printf("\n");

    return 0;
}
 */