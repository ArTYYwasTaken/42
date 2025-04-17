/* #include "libft.h"
#include <stdlib.h>

static void free_memory(char **str, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(str[i]);
    }
    free(str);
}

static size_t count_words(char const *s, char c) {
    size_t i = 0;
    size_t count = 0;

    while (s[i]) {
        while (s[i] && s[i] == c)
            i++;
        if (s[i] && s[i] != c) {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return count;
}

static void fill_arr(char **str, char const *s, size_t count, char c) {
    size_t i = 0;
    size_t mat_index = 0;

    while (mat_index < count) {
        size_t arr_i = 0;
        while (s[i] && s[i] == c)
            i++;
        while (s[i] && s[i] != c)
            str[mat_index][arr_i++] = s[i++];
        str[mat_index][arr_i] = '\0';
        mat_index++;
    }
    str[mat_index] = NULL;
}

static int split_str(char **str, char const *s, size_t count, char c) {
    size_t i = 0;
    size_t mat_index = 0;

    while (mat_index < count) {
        size_t arr_i = 0;
        while (s[i] && s[i] == c)
            i++;
        while (s[i] && s[i] != c) {
            arr_i++;
            i++;
        }
        str[mat_index] = (char *)malloc((arr_i + 1) * sizeof(char));
        if (!str[mat_index]) {
            free_memory(str, mat_index);
            return 0;
        }
        mat_index++;
    }
    return 1;
}

char **ft_split(char const *s, char c) {
    if (!s)
        return NULL;

    size_t total_words = count_words(s, c);
    char **matriz = (char **)malloc((total_words + 1) * sizeof(char *));
    if (!matriz)
        return NULL;

    if (!split_str(matriz, s, total_words, c)) {
        return NULL;
    }

    fill_arr(matriz, s, total_words, c);
    return matriz;
}

#include "libft.h"

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
} */