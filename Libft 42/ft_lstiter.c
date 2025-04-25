/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:16:28 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 20:31:05 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The function ft_lstiter applies the function 'f' to the content of each
	element in the linked list 'lst'.
	It iterates through the list and applies the function to each element's
	content.

    PARAMETERS:
	- t_list *lst: A pointer to the head of the list.
	- void (*f)(void *): A function pointer to the function to be applied to
	  the content of each element.

    RETURN VALUE:
	- None.
	- The function modifies the content of each element in the list in place,
	  so it does not return anything.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
/*
// TEST CODE
void put_a(void *content)
{
	char	*str;

	str = (char *)content;
	str[0] = 'a';
}

int	main(void)
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

	temp = node1;
	printf("Antes\n");
	while(temp)
	{
		printf("\n%s\n",  (char *)temp->content);
		temp = temp->next;
	}
	ft_lstiter(node1, put_a);
	temp = node1;
	printf("Depois:\n");
	while(temp)
	{
		printf("\n%s\n",  (char *)temp->content);
		temp = temp->next;
	}
}
*/