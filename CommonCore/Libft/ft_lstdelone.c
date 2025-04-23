/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:05:02 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/21 19:08:31 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if(lst && del)
	{
		(del)(lst->content);
		free(lst);
        lst = NULL;
	}
}

// TEST CODE
void print_node(t_list *node)
{
    if (node && node->content)
        printf("%s\n", (char *)node->content);
    else
        printf("Node is NULL or content is NULL\n");
}

int main(void)
{
    // 1. Allocate content dynamically
    char *str = malloc(20);
    if (!str)
        return 1;
    strcpy(str, "Hello, world!");

    // 2. Create a new node with this content
    t_list *node = ft_lstnew(str);
    if (!node)
    {
        free(str);
        return 1;
    }

    printf("Before deletion:\n");
    print_node(node);

    // 3. Delete the node using ft_lstdelone and free as del function
    ft_lstdelone(node, free);

    // 4. After deletion, node pointer is invalid (freed), so don't access it!
    printf("After deletion:\n");
    printf("Node has been deleted and memory freed.\n");

    return 0;
}