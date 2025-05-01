/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:23:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 18:21:05 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static void *put_a_copy(void *content)
{
    char *str = (char *)content;
    char *new_str = strdup(str);
    if (!new_str)
        return NULL;
    new_str[0] = 'A';
    return new_str;
}

int	main()
{
	t_list *node2;
    t_list *node3;
    t_list *node4;
    t_list *node5;
    t_list *current;
    t_list *new_list;
    t_list *head = NULL;

    head = ft_lstnew(strdup("1"));
    node2 = ft_lstnew(strdup("2"));
    node3 = ft_lstnew(strdup("3"));
    node4 = ft_lstnew(strdup("4"));
    node5 = ft_lstnew(strdup("5"));

    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    ft_lstadd_back(&head, node4);
    ft_lstadd_back(&head, node5);

    current = head;

    printf("Lista original:\n");
    while (current)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    new_list = ft_lstmap(head, put_a_copy, free);
    current = new_list;

    printf("Lista nova:\n");
    while (current)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    ft_lstclear(&head, free);
    ft_lstclear(&new_list, free);

    return 0;
}
*/