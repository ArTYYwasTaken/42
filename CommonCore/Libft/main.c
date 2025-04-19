#include "libft.h"

// TEST CODE
int main(void)
{
    char *str = "Hello, World!";
    t_list *node = ft_lstnew(str);

    if (!node)
    {
        printf("Failed to allocate memory for new list node.\n");
        return 1;
    }
    if (node->content == NULL)
        printf("Node content is NULL.\n");
    else
        printf("Node content: %s\n", (char *)node->content);
    free(node);
    return 0;
}