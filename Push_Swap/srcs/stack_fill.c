/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:08:21 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 17:54:29 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_new(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*last;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->index = 0;
	new_node->next = NULL;
	if (!(*stack))
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		last = stack_last(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	indexing(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = (*stack);
	while (current)
	{
		compare = (*stack);
		while (compare)
		{
			if (current->num > compare->num)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

bool	fill_stack(t_stack **stack_a, char **args)
{
	long	num;
	size_t	i;

	if (!args_validation(args))
		return (print_error(), false);
	i = 0;
	while (args[i])
	{
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX || num_len(num) > 10)
			return (print_error(), false);
		stack_new(stack_a, (int)num);
		if (!check_num_dups(*stack_a))
			return (print_error(), false);
		i++;
	}
	indexing(stack_a);
	return (true);
}
