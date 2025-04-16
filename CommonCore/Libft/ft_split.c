/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:06 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/16 18:57:38 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void free_memory(char **str, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
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

static int split_str(char **str, char const *s, size_t count, char c)
{
	size_t i;
	size_t arr_i;
	size_t mat_index;

	i = 0;
	mat_index = 0;
	while (mat_index < count)
	{
		arr_i = 0;
		while(s[i] && s[i] == c)
			i++;
		while(s[i] && s[i] != c)
		{	
			arr_i++;
			i++;
		}
		str[mat_index] =(char *)malloc((arr_i + 1) * sizeof(char));
		if(!str[mat_index])
		{
		   free_memory(str, count);
		   return 0;
		}
		mat_index++;
	}
	return 1;
}

static void fill_arr(char **str,char const *s, size_t count, char c)
{
    size_t i;
    size_t arr_i;
    size_t mat_index; 

    i = 0; 
    mat_index = 0;
    while (mat_index < count)
    {
        arr_i = 0;
         while(s[i] && s[i] == c)
            i++;
        while (s[i] && s[i] != c)
            str[mat_index][arr_i++] = s[i++];
        str[mat_index][arr_i] = '\0';
        mat_index++;
    }
    str[mat_index] = NULL;
}

char **ft_split(char const *s, char c)
{
    if (!s)
        return (NULL);

    char **matriz;
    size_t  total_words;
    total_words = count_words(s, c);
    matriz = (char**)malloc((total_words + 1 )* sizeof(char *));
    if(!matriz)
        return (NULL);
    if(!split_str(matriz, s, total_words, c))
		return (NULL);
    fill_arr(matriz, s, total_words, c);    
    return (matriz);
}
/* 
int main(void)
{
    char **result;
    char *test_str = "Hello,world,this,is,a,test";
    char delimiter = ',';
    int i = 0;

    result = ft_split(test_str, delimiter);
    if (!result)
    {
        printf("Error: ft_split returned NULL\n");
        return 1;
    }

    printf("Splitting string: \"%s\" by delimiter '%c'\n", test_str, delimiter);
    while (result[i])
    {
        printf("Segment %d: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
} */