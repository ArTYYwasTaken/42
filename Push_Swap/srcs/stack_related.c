/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:39:16 by marvin            #+#    #+#             */
/*   Updated: 2025/09/18 18:49:37 by kemontei         ###   ########.fr       */
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

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	if (stack)
	{
		while (*stack)
		{
			temp = (*stack)->next;
			free(*stack);
			*stack = temp;
		}
	}
	*stack = NULL;
}
