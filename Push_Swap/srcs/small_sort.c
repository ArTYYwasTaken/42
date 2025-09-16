/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:30:21 by marvin            #+#    #+#             */
/*   Updated: 2025/09/15 15:26:12 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*index_node(t_stack *stack_a, int index)
{
	t_stack	*node;

	while (stack_a)
	{
		if (stack_a->index == index)
			node = stack_a;
		stack_a = stack_a->next;
	}
	return (node);
}

static void	sort_three(t_stack **stack_a)
{
	t_stack	*big;

	big = index_node(*stack_a, 2);
	if (big->index == (*stack_a)->index)
		ra(stack_a);
	else if (big->index == (*stack_a)->next->index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*small;
	t_stack *second;
	t_stack *third;
	t_stack *last;

	small = index_node(*stack_a, 0);
	second = (*stack_a)->next;
	last = stack_last(*stack_a);
	third = last->prev;
	if (second->index == small->index)
		sa(stack_a);
	else if (third->index == small->index)
		(rra(stack_a), rra(stack_a));
	else if (last->index == small->index)
		(rra(stack_a));
	if (small->index == (*stack_a)->index)
		pb(stack_b, stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *small;
	t_stack *second;
	t_stack *third;
	t_stack	*forth;
	t_stack *last;

	small = index_node(*stack_a, 0);
	second = (*stack_a)->next;
	third = second->next;
	last = stack_last(*stack_a);
	forth = last->prev;
	if (second->index == small->index)
		sa(stack_a);
	else if (third->index == small->index)
		(ra(stack_a), ra(stack_a));
	else if (forth->index == small->index)
		(rra(stack_a), rra(stack_a));
	else if (last->index == small->index)
		(rra(stack_a));
	if (small->index == (*stack_a)->index)
		pb(stack_b, stack_a);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 3)
		sort_three(stack_a);
	else
		sa(stack_a);
}
