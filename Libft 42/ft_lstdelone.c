/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:05:02 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/24 20:31:31 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The function ft_lstdelone deletes a single element from a linked list.
	It takes a pointer to the element to be deleted and a function pointer to
	the function that deletes the content of the element.
	It frees the memory allocated for the content of the element and the element
	itself.

    PARAMETERS:
	- t_list *lst: A pointer to the element to be deleted.
	- void (*del)(void *): A function pointer to the function that deletes the
	  content of the element.

	NOTE:
	- The function does not delete the next element in the list.
	- The function does not set the next pointer of the previous element to
	  NULL.
	- The function does not free the memory allocated for the element itself.
	- The function does not set the head pointer of the list to NULL.

	RETURN VALUE:
	- None.
	- The function modifies the list in place, so it does not return anything.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
/* 
// TEST CODE
int main()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *temp;


	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node4 = malloc(sizeof(t_list));

	node1->content = ft_strdup("1");
	node2->content = ft_strdup("2");
	node3->content = ft_strdup("3");
	node4->content = ft_strdup("4");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;;

	node2->next = node4;
	temp = node1;
	ft_lstdelone(node3, free);
	while(temp)
	{
		printf("\n%s\n",  (char *)temp->content);
		temp = temp->next;
	}
}
*/