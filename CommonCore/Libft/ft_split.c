/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:06 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/15 18:55:47 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t ft_substrlen(char const *s, char c)
{
    size_t i;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        if (s[i + 1] != c)
            i++;
        if (s[i] != c && s[i + 1] == c)
            i++;
    }
    return (i);
} */
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

static void split_str(char **str, char const *s, size_t count, char c)
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
            arr_i++;
        str[mat_index] =(char *) malloc((arr_i + 1) * sizeof(char));
        if(!str[arr_i++])
        {
            str = NULL;
            break;
        }
    }
}

static size_t	count_words(char const *s, char c)
{
    size_t	i;
    size_t	count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        if (s[i + 1] != c)
            i++;
        if (s[i] != c && s[i + 1] == c)
        {
            count++;
            i++;
        }
        if(s[i] != c && s[i + 1] == '\0')
            count++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    char **matriz;
    size_t  total_words;
    total_words = count_words(s, c);
    if (!s)
        return (NULL);
    matriz = (char**)malloc(total_words * sizeof(char *) + 1);
    if(!matriz)
        return (NULL);
    split_str(matriz, s, total_words, c);
    if (matriz == NULL)
        return (NULL);
    fill_arr(matriz, s, total_words, c);    
    return (matriz);
}

int main()
{
    char str[] = "banana, uva, maca, pera";
    char **matriz = ft_split(str, ',');
   printf("%s", matriz[0]);
}
