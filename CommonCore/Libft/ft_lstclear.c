/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:10:42 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/21 19:11:03 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *current;
    t_list  *next;

    current = *lst;
    if (!del || !lst || !*lst)
        return ;
    while(current)
    {
        next = current->next;
        (del)(current->content);
        free(current);
        current = next;
    }
        *lst = NULL;
}