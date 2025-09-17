/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:34:18 by marvin            #+#    #+#             */
/*   Updated: 2025/09/17 18:26:36 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	head = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last = stack_last(*stack_a);
	last->next = head;
	head->prev = last;
	head->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*last;

	if (!stack_b || !(*stack_b) || (*stack_b)->next)
		return ;
	head = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last = stack_last(*stack_b);
	last->next = head;
	head->prev = last;
	head->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}
