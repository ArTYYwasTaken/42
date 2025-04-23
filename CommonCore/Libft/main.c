#include "libft.h"

int main()
{
    t_list *node;
    t_list *node2;
    t_list *node3;

	node = ft_lstnew("Bleach");
	node2 = ft_lstnew("Naruto");
	node3 = ft_lstnew("One Piece");

    node->next = node2;
    node2->next = node3;

	t_list *head = node;
	t_list *current = head;

	printf("\n---//Node Contents//---\n");
	while(current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

    ft_lstclear(&node, free);

    // Check if the list is cleared
    if (!node)
        printf("List cleared successfully\n");
    else
        printf("List not cleared\n");
    return 0;
}