/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:05:02 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:04:27 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
/* 
int main()
{
	t_list *head;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	t_list *current;

	head = ft_lstnew(strdup("1"));
    node2 = ft_lstnew(strdup("2"));
    node3 = ft_lstnew(strdup("3"));
    node4 = ft_lstnew(strdup("4"));

    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    ft_lstadd_back(&head, node4);

	node2->next = node4;
	current = head;
	ft_lstdelone(node3, free);

	while(current)
	{
		printf("\n%s\n",  (char *)current->content);
		current = current->next;
	}
}
*/