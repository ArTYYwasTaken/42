/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:10:42 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/24 21:44:11 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The function ft_lstclear clears a linked list by deleting all its elements.
	It takes a pointer to the head of the list and a function pointer to delete
	the content of each element.
	It frees the memory allocated for each element and sets the head pointer to
	NULL.

    PARAMETERS:
	- t_list **lst: A pointer to the head of the list.
	- void (*del)(void *): A function pointer to the function that deletes the
	  content of each element.

    RETURN VALUE:
	- None.
	- The function modifies the list in place, so it does not return anything.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!del || !lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		(del)(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/* 
int main()
{
	t_list *head = ft_lstnew(ft_strdup("Bleach"));
    t_list *node2 = ft_lstnew(ft_strdup("Naruto"));
    t_list *node3 = ft_lstnew(ft_strdup("One Piece"));

    head->next = node2;
    node2->next = node3;

    t_list *current = head;

    printf("\n---//Node Contents Before Clear//---\n");
    while (current)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    ft_lstclear(&head, free);

    if (!head)
        printf("List cleared successfully\n");
    else
        printf("List not cleared\n");

    return 0;
}
*/