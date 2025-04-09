#include "libft.h"

int main()
{
    char dest[10];
    char src[] = "Kaio";
    size_t n = 4;

    size_t result = ft_strlcpy(dest, src, n);
    printf("ft_strlcpy result: %ld\n", result);
    printf("Destination string: %s\n", dest);

    // Uncomment the following lines if you want to compare with the standard strlcpy
    // size_t std_result = strlcpy(dest, src, n);
    // printf("strlcpy result: %ld\n", std_result);
    // printf("Destination string: %s\n", dest);

    return 0;
}