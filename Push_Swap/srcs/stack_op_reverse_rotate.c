/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 03:50:53 by marvin            #+#    #+#             */
/*   Updated: 2025/09/13 03:50:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;

		if (!stack_a || !(*stack_a) || !(*stack_a)->next)
			return;
	last = stack_last(*stack_a);
	last->prev->next = NULL;
	last->next = (*stack_a);
	(*stack_a)->prev = last;
	(*stack_a) = last;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;

		if (!stack_b || !(*stack_b) || !(*stack_b)->next)
			return;
	last = stack_last(*stack_b);
	last->prev->next = NULL;
	last->next = (*stack_b);
	(*stack_b)->prev = last;
	(*stack_b) = last;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
