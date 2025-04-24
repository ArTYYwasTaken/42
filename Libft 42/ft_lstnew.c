/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:03 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/24 21:44:26 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION:
    The ft_lstnew() function creates a new node for a linked list.
    It allocates memory for the new node, sets its content to the given value,
    and initializes its next pointer to NULL.
    The content of the new node is set to the value passed as an argument.

    PARAMETERS:
    - void *content: The content to be set in the new node.

    RETURN VALUE:
    The function returns a pointer to the newly created node.
    If the memory allocation fails, it returns NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/* 
int main(void)
{
    t_list *node = ft_lstnew("Sosuke Aizen");

    if (!node)
		return 1;
    if (!node->content)
        printf("\nNode content is NULL.\n");
    else
        printf("\n---//Node content//---\n%s\n\n", (char *)node->content);
    free(node);
    return 0;
}
*/