/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:16:28 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 16:53:41 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void put_a(void *content)
{
	char	*str;

	str = (char *)content;
	str[0] = 'a';
}

int	main()
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

	current = head;

	printf("Antes\n");
	while(current)
	{
		printf("\n%s\n",  (char *)current->content);
		current = current->next;
	}

	ft_lstiter(head, put_a);
	current = head;

	printf("Depois:\n");
	while(current)
	{
		printf("\n%s\n",  (char *)current->content);
		current = current->next;
	}

	ft_lstclear(&head, free);

	return 0;
}
 */