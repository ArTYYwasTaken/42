/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:20:58 by marvin            #+#    #+#             */
/*   Updated: 2025/09/11 17:20:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (!stack_b || !(*stack_b))
		return ;
	first = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	first->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = first;
	first->prev = NULL;
	*stack_a = first;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*first;

	if (!stack_a || !(*stack_a))
		return;
	first = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	first->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = first;
	first->prev = NULL;
	*stack_b = first;
	ft_putstr_fd("pb\n", 1);
}
