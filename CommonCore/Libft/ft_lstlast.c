/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:08:45 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/21 18:30:47 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if(!lst)
		return (NULL);
	while(lst->next)
		lst = lst->next;
	return (lst);
}
/* 
// TEST CODE
int main()
{
	t_list *node1 = ft_lstnew("Kaio");
	t_list *node2 = ft_lstnew("Rafinha");
	t_list *node3 = ft_lstnew("Nata");
	t_list *node4 = ft_lstnew("Kelle");
	t_list *last;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	last = ft_lstlast(node1);

	printf("Last node: %s\n", (char *)last->content);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return 0;
} */