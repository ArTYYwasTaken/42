/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:10:42 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 19:14:23 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (!del || !lst || !*lst)
		return ;
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
//TEST CODE
int main()
{
    // Create a linked list with three nodes
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
 */