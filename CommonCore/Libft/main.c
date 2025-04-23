#include "libft.h"

// TEST CODE
int main()
{
    t_list *node;
	t_list *node2;
	t_list *new;
	t_list *head;
	t_list *temp;

	node = ft_lstnew("Bleach");
	node2 = ft_lstnew("Naruto");
	new = ft_lstnew("One Piece");
	node->next = node2;
	
	head = node;
	temp = head;
	
	printf("\n---//Before Changes//---\n");
	while(temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}

	ft_lstadd_back(&head, new);
	temp = head;

	printf("\n---//After Changes//---\n");
	while(temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
	printf("\n");

	t_list *current = head;
	t_list *next;

	while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}