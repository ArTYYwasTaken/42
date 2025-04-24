/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:16 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 22:21:36 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The function ft_lstadd_back adds a new element to the end of a linked list.
	It takes a pointer to the head of the list and a pointer to the new element

    PARAMETERS:
	- t_list **lst: A pointer to the head of the list.
	- t_list *new: A pointer to the new element to be added.

    RETURN VALUE:
	- None.
	- The function modifies the list in place, so it does not return anything.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/* 
// TEST CODE
int main()
{
    t_list *node;
	t_list *node2;
	t_list *new;
	t_list *head;
	t_list *current;

	node = ft_lstnew("Bleach");
	node2 = ft_lstnew("Naruto");
	new = ft_lstnew("One Piece");
	node->next = node2;
	
	head = node;
	current = head;
	
	printf("\n---//Before Changes//---\n");
	while(current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	ft_lstadd_back(&head, new);
	current = head;

	printf("\n---//After Changes//---\n");
	while(current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("\n");

	current = head;
	t_list *next;

	while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
 */