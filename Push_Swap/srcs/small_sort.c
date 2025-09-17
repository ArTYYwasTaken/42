// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   small_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/09/15 02:30:21 by marvin            #+#    #+#             */
// /*   Updated: 2025/09/17 18:52:20 by kemontei         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static t_stack	*index_node(t_stack *stack_a, int index)
// {
// 	t_stack	*node;

// 	while (stack_a)
// 	{
// 		if (stack_a->index == index)
// 			return (stack_a);
// 		stack_a = stack_a->next;
// 	}
// 	return (NULL);
// }

// static void	sort_three(t_stack **stack_a)
// {
// 	t_stack	*big;

// 	big = index_node(*stack_a, 2);
// 	if (big->index == (*stack_a)->index)
// 		ra(stack_a);
// 	else if (big->index == (*stack_a)->next->index)
// 		rra(stack_a);
// 	if ((*stack_a)->index > (*stack_a)->next->index)
// 		sa(stack_a);
// }

// static void	sort_four(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*small;
// 	t_stack	*second;
// 	t_stack	*third;
// 	t_stack	*last;

// 	small = index_node(*stack_a, 0);
// 	second = (*stack_a)->next;
// 	last = stack_last(*stack_a);
// 	third = last->prev;
// 	if (second->index == small->index)
// 		sa(stack_a);
// 	else if (third->index == small->index || last->index == small->index)
// 		while((*stack_a)->index != small->index)
// 			rra(stack_a);
// 	// else if (third->index == small->index)
// 	// 	(rra(stack_a), rra(stack_a));
// 	// else if (last->index == small->index)
// 	// 	(rra(stack_a));
// 	if (small->index == (*stack_a)->index)
// 		pb(stack_b, stack_a);
// 	sort_three(stack_a);
// 	pa(stack_a, stack_b);
// }

// static void	sort_five(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*small;
// 	t_stack	*second;
// 	t_stack	*third;
// 	t_stack	*forth;
// 	t_stack	*last;

// 	small = index_node(*stack_a, 0);
// 	second = (*stack_a)->next;
// 	third = second->next;
// 	last = stack_last(*stack_a);
// 	forth = last->prev;
// 	if (second->index == small->index)
// 		sa(stack_a);
// 	else if (third->index == small->index)
// 		(ra(stack_a), ra(stack_a));
// 	else if (forth->index == small->index)
// 		(rra(stack_a), rra(stack_a));
// 	else if (last->index == small->index)
// 		(rra(stack_a));
// 	if (small->index == (*stack_a)->index)
// 		pb(stack_b, stack_a);
// 	sort_four(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// }

// void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	if (size == 5)
// 		sort_five(stack_a, stack_b);
// 	else if (size == 4)
// 		sort_four(stack_a, stack_b);
// 	else if (size == 3)
// 		sort_three(stack_a);
// 	else
// 		sa(stack_a);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:30:21 by marvin            #+#    #+#             */
/*   Updated: 2025/09/17 20:30:00 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Return the node whose index equals `index`, or NULL if not found.
** Previously this returned an uninitialized pointer when not found,
** causing segfaults on dereference.
*/
static t_stack	*index_node(t_stack *stack_a, int index)
{
	while (stack_a)
	{
		if (stack_a->index == index)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

/*
** Find the maximum `index` value currently present in the stack.
** Returns -1 if stack is NULL (indices are assumed to be >= 0).
*/
static int	find_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

/*
** Sort exactly three elements on stack_a.
** We rotate based on the position of the current maximum index in the
** 3-node list, not on a hard-coded value (2), because the remaining
** indices after previous operations may not be {0,1,2}.
**
** Algorithm:
** - Bring the max to the bottom:
**   - If max is at top: ra
**   - Else if max is in second position: rra
** - Then ensure the first two are in order with sa if needed.
*/
static void	sort_three(t_stack **stack_a)
{
	int		max_idx;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	max_idx = find_max_index(*stack_a);
	/* Bring max to bottom */
	if ((*stack_a)->index == max_idx)
		ra(stack_a);
	else if ((*stack_a)->next && (*stack_a)->next->index == max_idx)
		rra(stack_a);
	/* Now fix the first two if needed */
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*small;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	small = index_node(*stack_a, 0);
	if (!small)
		return ;
	second = (*stack_a)->next;
	last = stack_last(*stack_a);
	third = (last ? last->prev : NULL);
	if (second && second->index == small->index)
		sa(stack_a);
	else if ((third && third->index == small->index)
		|| (last && last->index == small->index))
		while ((*stack_a) && (*stack_a)->index != small->index)
			rra(stack_a);
	if (*stack_a && small->index == (*stack_a)->index)
		pb(stack_b, stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*small;
	t_stack	*second;
	t_stack	*third;
	t_stack	*forth;
	t_stack	*last;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	small = index_node(*stack_a, 0);
	if (!small)
		return ;
	second = (*stack_a)->next;
	third = (second ? second->next : NULL);
	last = stack_last(*stack_a);
	forth = (last ? last->prev : NULL);
	if (second && second->index == small->index)
		sa(stack_a);
	else if (third && third->index == small->index)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (forth && forth->index == small->index)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (last && last->index == small->index)
		rra(stack_a);
	if (*stack_a && small->index == (*stack_a)->index)
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
