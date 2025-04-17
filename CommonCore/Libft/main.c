#include "libft.h"

char example_function(unsigned int index, char c) {
    // For demonstration, alternate case based on index
    if (index % 2 == 0)
	{
        // Convert to uppercase if index is even
        if (c >= 'a' && c <= 'z')
            return c - 32;
    } else {
        // Convert to lowercase if index is odd
        if (c >= 'A' && c <= 'Z')
            return c + 32;
    }
    return c;
}

int main()
{
    char *original = "hello world";
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