#include "libft.h"

// TEST CODE
int main() {
    int test_values[] = {0, 123, -123, 2147483647, -2147483648};
    size_t num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_itoa(test_values[i]);
        if (result) {
            printf("ft_itoa(%d) = %s\n", test_values[i], result);
            free(result); // Free the allocated memory
        } else {
            printf("ft_itoa(%d) failed to allocate memory\n", test_values[i]);
        }
    }

    return 0;
}