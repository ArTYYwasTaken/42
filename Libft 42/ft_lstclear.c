/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:10:42 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:47:02 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_lstdelone(current, (del));
		current = next;
	}
	*lst = NULL;
}
/* 
int main()
{
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

    return 0;
}
 */