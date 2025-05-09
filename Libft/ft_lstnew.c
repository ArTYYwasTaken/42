/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:03 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/25 17:13:56 by kemontei         ###   ########.fr       */
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