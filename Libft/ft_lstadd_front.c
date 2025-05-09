/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:21:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:04:17 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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