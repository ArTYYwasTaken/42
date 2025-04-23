/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:24:15 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 17:15:42 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	// if (!lst)
	// 	return (NULL);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* 
// TEST CODE
int main()
{
	t_list *node1 = ft_lstnew("Kurosaki");
	t_list *node2 = ft_lstnew("Ichigo");
	t_list *node3 = ft_lstnew("Sosuke");
	t_list *node4 = ft_lstnew("Aizen");
	int size;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	size = ft_lstsize(node1);

	printf("List size: %d\n", size);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return 0;
}
 */