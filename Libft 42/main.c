#include "libft.h"

// TEST CODE
char example_function(unsigned int index, char c)
{
    if (index % 2 == 0)
	{
        if (c >= 'a' && c <= 'z')
            return c - 32;
    } else
	{
        if (c >= 'A' && c <= 'Z')
            return c + 32;
    }
    return c;
}

int main()
{
    char *original = "sosuke aizen";
    char *result = ft_strmapi(original, example_function);

    if (result)
	{
        printf("\nOriginal: %s\n", original);
        printf("Transformed: %s\n\n", result);
        free(result);
    } else
        printf("Error: Memory allocation failed.\n\n");
    return 0;
}