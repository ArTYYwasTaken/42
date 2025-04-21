/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:32:16 by kemontei          #+#    #+#             */
/*   Updated: 2025/04/21 19:04:31 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *other;

    if (lst && new)
    {
        if (!*lst)
            *lst = new;
        else
        {
            other = ft_lstlast(*lst);
            other->next = new;
        }
    }
}
