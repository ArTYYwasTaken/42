/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:21:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/24 21:44:08 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The function ft_lstadd_front adds a new element to the front of a linked
	list.
	It takes a pointer to the head of the list and a pointer to the new element.

    PARAMETERS:
	- t_list **lst: A pointer to the head of the list.
	- t_list *new: A pointer to the new element to be added.

    RETURN VALUE:
	- None.
	- The function modifies the list in place, so it does not return anything.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			new->next = *lst;
			*lst = new;
		}
	}
}
/* 
int main()
{
	t_list *node;
	t_list *node2;
	t_list *head;
	t_list *current;

	node = ft_lstnew("Yhwach");
	node2 = ft_lstnew("Jugram");
	node->next = node2;

	head = node;
	current = head;

	printf("\n---//Before changes//---\n");
	while(current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	node->next = NULL;
	ft_lstadd_front(&head, node2);
	current = head;

	printf("\n---//After changes//---\n");
	while(current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("\n");
	free (node);
	free (node2);
	return 0;
}
*/
