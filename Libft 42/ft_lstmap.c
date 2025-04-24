/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:23:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/23 22:29:40 by kemontei         ###   ########.fr       */
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
	t_list	*newlist;
	t_list	*newnode;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newcontent = (f)(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newcontent || !newnode)
		{
			(del)(newcontent);
			ft_lstclear(&newlist, del);
			free(newnode);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
