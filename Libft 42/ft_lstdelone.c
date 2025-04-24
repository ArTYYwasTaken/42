/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:05:02 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/23 18:03:56 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
	The function ft_lstdelone deletes a single element from a linked list.
	It takes a pointer to the element to be deleted and a function pointer to
	the function that deletes the content of the element.
	It frees the memory allocated for the content of the element and the element
	itself.

    PARAMETERS:
	- t_list *lst: A pointer to the element to be deleted.
	- void (*del)(void *): A function pointer to the function that deletes the
	  content of the element.

	NOTE:
	- The function does not delete the next element in the list.
	- The function does not set the next pointer of the previous element to
	  NULL.
	- The function does not free the memory allocated for the element itself.
	- The function does not set the head pointer of the list to NULL.

	RETURN VALUE:
	- None.
	- The function modifies the list in place, so it does not return anything.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
/* 
// TEST CODE
int main()
{
	
}
*/