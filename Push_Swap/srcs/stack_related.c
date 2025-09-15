/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:39:16 by marvin            #+#    #+#             */
/*   Updated: 2025/09/05 05:39:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

bool	stack_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (false);
	while (stack_a->next)
		if (stack_a->next->num > stack_a->num)
			stack_a = stack_a->next;
	else
		return (false);
	return (true);
}
