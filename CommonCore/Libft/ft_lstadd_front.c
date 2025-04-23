/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:21:28 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/21 18:46:50 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;	
		*lst = new;
	}
}
/* 
// TEST CODE
int main()
{
	t_list *node;
	t_list *node2;
	t_list *head;
	t_list *temp;

	node = ft_lstnew("Kelle");
	node2 = ft_lstnew("Silva");
	node->next = node2;

	head = node;
	temp = head;

	printf("\n---//Before changes//---\n");
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	node->next = NULL;
	ft_lstadd_front(&head, node2);
	temp = head;
	printf("\n");

	printf("---//After changes//---\n");
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	free (node);
	free (node2);
	return 0;
}
 */
