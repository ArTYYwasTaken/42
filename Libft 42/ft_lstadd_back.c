/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:16 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 17:33:32 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	last = ft_lstlast(*lst);
	last->next = new;
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