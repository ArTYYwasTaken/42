/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:03 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/21 14:59:51 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
// TEST CODE
int main(void)
{
    char *str = "Hello, World!";
    t_list *node = ft_lstnew(str);

    if (!node)
    {
        printf("Failed to allocate memory for new list node.\n");
        return 1;
    }
    if (node->content == NULL)
        printf("Node content is NULL.\n");
    else
        printf("Node content: %s\n", (char *)node->content);
    free(node);
    return 0;
}
*/