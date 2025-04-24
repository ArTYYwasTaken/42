/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:16:28 by marvin            #+#    #+#             */
/*   Updated: 2025/04/23 19:56:35 by kemontei         ###   ########.fr       */
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
