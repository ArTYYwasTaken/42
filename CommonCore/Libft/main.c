#include "libft.h"

// TEST CODE
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
}