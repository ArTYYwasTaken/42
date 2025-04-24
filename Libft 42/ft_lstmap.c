/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:23:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 21:44:20 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The ft_lstmap() function applies the function f to each node of the list
	lst, and creates a new list with the results of the function applications.
	The new list is created using the function ft_lstnew(). If the application
	of the function f fails, the function del is called on the content of the
	new node, and the new list is cleared using ft_lstclear().

    PARAMETERS:
	- t_list *lst: A pointer to the head of the list.
	- void *(*f)(void *): A pointer to the function to be applied to each node's
	  content.
	- void (*del)(void *): A pointer to the function to be called to delete the
	  content of a node if the application of f fails.

    RETURN VALUE:
	- A pointer to the new list created by applying f to each node's content.
	  If the application of f fails, NULL is returned and the new list is
	  cleared.
	  If lst is NULL, NULL is returned.
	  If f or del is NULL, NULL is returned.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newnode;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	newhead = NULL;
	while (lst)
	{
		newcontent = (f)(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newcontent || !newnode)
		{
			(del)(newcontent);
			ft_lstclear(&newhead, del);
			free(newnode);
			return (NULL);
		}
		ft_lstadd_back(&newhead, newnode);
		lst = lst->next;
	}
	return (newhead);
}
/*
// TEST CODE
static void	*put_a(void *content)
{
	char	*str;

	str = (char *)content;
	str[0] = 'a';
	return (str);
}

static void	free_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *node5;
	t_list *temp;
	t_list *new_list;
	t_list *head = NULL;

	node1 = ft_lstnew(ft_strdup("1"));
	node2 = ft_lstnew(ft_strdup("2"));
	node3 = ft_lstnew(ft_strdup("3"));
	node4 = ft_lstnew(ft_strdup("4"));
	node5 = ft_lstnew(ft_strdup("5"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	ft_lstadd_back(&head, node4);
	ft_lstadd_back(&head, node5);

	temp = head;
	printf("Lista original:\n");
	while (temp)
	{
		printf("\n%s\n", (char *)temp->content);
		temp = temp->next;
	}

	new_list = ft_lstmap(head, put_a, free_content);

	temp = new_list;
	printf("Lista nova:\n");
	while (temp)
	{
		printf("\n%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&new_list, free);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);

}
*/